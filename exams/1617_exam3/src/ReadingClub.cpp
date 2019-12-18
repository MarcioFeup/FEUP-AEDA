/*
 * ReadingClub.cpp
 *
 *  Created on: 11/12/2016
 *      Author: RRossetti
 */

#include "ReadingClub.h"

ReadingClub::ReadingClub() : catalogItems(BookCatalogItem("", "", 0)) {
	//do nothing!
}

ReadingClub::ReadingClub(vector<Book *> books) : catalogItems(BookCatalogItem("", "", 0)) {
	this->books = books;
}

void ReadingClub::addBook(Book *book) {
	this->books.push_back(book);
}

void ReadingClub::addBooks(vector<Book *> books) {
	this->books = books;
}

vector<Book *> ReadingClub::getBooks() const {
	return this->books;
}

BookCatalogItem ReadingClub::getCatalogItem(string title, string author) {
	BookCatalogItem itemNotFound("", "", 0);
	BSTItrIn<BookCatalogItem> it(catalogItems);
	while (!it.isAtEnd()) {
		if (it.retrieve().getTitle() == title && it.retrieve().getAuthor() == author) {
			BookCatalogItem bci(it.retrieve().getTitle(), it.retrieve().getAuthor(), 0);
			bci.setItems(it.retrieve().getItems());
			return bci;
		}
		it.advance();
	}
	return itemNotFound;
}

void ReadingClub::addCatalogItem(Book *book) {
	BookCatalogItem itemNotFound("", "", 0);
	BookCatalogItem bci(book->getTitle(), book->getAuthor(), book->getYear());
	BookCatalogItem bciX = catalogItems.find(bci);
	if (bciX == itemNotFound) {
		bci.addItems(book);
		this->catalogItems.insert(bci);
	} else {
		this->catalogItems.remove(bciX);
		bciX.addItems(book);
		this->catalogItems.insert(bciX);
	}
	books.push_back(book);
}

BST<BookCatalogItem> ReadingClub::getCatalogItems() const {
	return this->catalogItems;
}

vector<UserRecord> ReadingClub::getUserRecords() const {
	vector<UserRecord> records;
	HashTabUserRecord::const_iterator it1 = this->userRecords.begin();
	HashTabUserRecord::const_iterator it2 = this->userRecords.end();
	for (; it1 != it2; it1++) {
		records.push_back(*it1);
	}
	return records;
}

void ReadingClub::setUserRecords(vector<UserRecord> &urs) {
	for (int i = 0; i < urs.size(); i++) userRecords.insert(urs[i]);
}

priority_queue<User> ReadingClub::getBestReaderCandidates() const {
	return readerCandidates;
}

void ReadingClub::setBestReaderCandidates(priority_queue<User> &candidates) {
	readerCandidates = candidates;
}



//
// TODO: Part I   - BST
//

void ReadingClub::generateCatalog() {
	BookCatalogItem notFound("", "", 0);

	for (Book *book : books) {
		BookCatalogItem toAdd(book->getTitle(), book->getAuthor(), book->getYear());
		BookCatalogItem bookCatalogFound = catalogItems.find(toAdd);

		if (bookCatalogFound == notFound) {
			toAdd.addItems(book);
			catalogItems.insert(toAdd);
		} else {
			catalogItems.remove(bookCatalogFound);
			bookCatalogFound.addItems(book);
			catalogItems.insert(bookCatalogFound);
		}
	}
}

vector<Book *> ReadingClub::getAvailableItems(Book *book) const {
	vector<Book *> temp;

	BookCatalogItem toFind(book->getTitle(), book->getAuthor(), book->getYear());
	BookCatalogItem toGet = catalogItems.find(toFind);

	for (Book *b : toGet.getItems())
		if (b->getReader() == nullptr)
			temp.push_back(b);

	return temp;
}

bool ReadingClub::borrowBookFromCatalog(Book *book, User *reader) {
	vector<Book *> available = getAvailableItems(book);

	if (!available.empty()) {
		Book *toBorrow = available[0];
		toBorrow->setReader(reader);
		reader->addReading(book->getTitle(), book->getAuthor());
		return true;
	}

	return false;
}


//
// TODO: Part II  - Hash Table
//

void ReadingClub::addUserRecord(User *user) {
	UserRecord record(user);
	userRecords.insert(record);
}

void ReadingClub::changeUserEMail(User *user, string newEMail) {
	UserRecord record = *userRecords.find(UserRecord(user));
	userRecords.erase(record);
	record.setEMail(std::move(newEMail));
	userRecords.insert(record);
}


//
// TODO: Part III - Priority Queue
//

void ReadingClub::addBestReaderCandidates(const vector<User> &candidates, int min) {
	for (const User &candidate : candidates) {

		if (candidate.numReadings() >= min)
			readerCandidates.push(candidate);
	}
}

int ReadingClub::awardReaderChampion(User &champion) {
	if (readerCandidates.empty()) // no candidates, no champion
		return 0;

	User winner = readerCandidates.top();
	readerCandidates.pop();

	if (readerCandidates.empty()) { // only one candidate
		champion = winner;
		readerCandidates.push(winner);
		return readerCandidates.size();
	}

	User second = readerCandidates.top();
	readerCandidates.push(winner);

	if (winner.numReadings() == second.numReadings()) {
		// if the second place has the same amount as the first, noone wins
		return 0;
	} else {
		champion = winner;
		return readerCandidates.size();
	}
}

