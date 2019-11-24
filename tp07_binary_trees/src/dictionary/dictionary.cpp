#include "dictionary.h"
#include "non_existing_word.h"
#include <iostream>
#include <fstream>

using namespace std;

Dictionary::Dictionary() : words(Word("", "")) {}

const BST<Word> &Dictionary::getWords() const {
	return words;
}

void Dictionary::read(ifstream &ifstream) {
	string word, meaning;

	while (!ifstream.eof()) {
		getline(ifstream, word);
		getline(ifstream, meaning);

		this->words.insert(Word(word, meaning));
	}
}

void Dictionary::print() const {
	for (auto it = words.begin(); it != words.end(); it++)
		cout << (*it);
}

std::string Dictionary::query(std::string word) const {
	BST<Word> tmp(words);
	Word aux_word(word, "");
	auto it = tmp.begin();
	Word previous("", "");
	Word next("", "");

	while (it != tmp.end() && *it < aux_word) {
		previous = *it;
		it++;
	}

	if (it != tmp.end()) {
		if (*it == aux_word)
			return (*it).getMeaning();
		next = *it;
	}

	throw NonExistingWord(previous, next);
}

bool Dictionary::amend(std::string word, std::string meaning) {
	Word to_amend(word, meaning);

	Word found = words.find(to_amend);
	if (found == Word("", "")) {
		words.insert(to_amend);
		return false;
	} else {
		words.remove(found);
		words.insert(to_amend);
		return true;
	}
}
