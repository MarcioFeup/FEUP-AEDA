#include "game.h"

#include <utility>
#include <vector>

using namespace std;

Game::Game() = default;

Game::Game(list<Child> &children) {
	this->children = children;
}

unsigned int Game::qtWords(string sentence) {
	if (sentence.length() == 0) return 0;

	unsigned n = 1;
	size_t pos = sentence.find(' ');
	while (pos != string::npos) {
		sentence = sentence.substr(pos + 1);
		pos = sentence.find(' ');
		n++;
	}
	return n;
}

void Game::addChild(const Child &child) {
	this->children.push_back(child);
}

list<Child> &Game::reverse() {

/*	Manual reverse:

	auto *res = new list<Child>();

	auto i = children.end();
	while(i != children.begin())
		res->push_back(*--i);

	children = *res;
	return *res;*/

	/* SDL reverse */
	children.reverse();
	return children;
}

list<Child> Game::divide(unsigned age) {
	list<Child> removed;

	for (auto it = children.begin(); it != children.end(); ++it) {
		if ((*it).getAge() > age) {
			removed.push_back(*it);
			it = children.erase(it);
		}
	}

	return removed;
}

Child &Game::whoLooses(string sentence) {
	unsigned qt_words = qtWords(std::move(sentence));

	auto it = children.begin();
	while (children.size() > 1) {
		it--; // the iterator was already initialized and needs to return to the first member
		for (unsigned i = 0; i < qt_words; ++i) {
			++it;

			if (it == children.end())
				it = children.begin();
		}

		it = children.erase(it);
		if (it == children.end())
			it = children.begin();
	}
	return *children.begin();
}

void Game::setChildren(const std::list<Child> &children) {
	this->children = children;
}

list<Child> Game::shuffle() const {
	vector<const Child *> tmp(children.size());
	unsigned long place;

	for (auto it = children.begin(); it != children.end(); ++it) {
		place = rand() % children.size();
		while (tmp[place] != NULL) {
			if (place == children.size()) {
				place = 0;
				continue;
			}
			place++;
		}
		tmp[place] = &(*it);
	}

	list<Child> shuffled;
	for (
		const Child *child
			: tmp)
		shuffled.
				push_back(*child);

	return
			shuffled;
}

string Game::describe() const {
	string description;

	for (const Child &child : children)
		description += child.describe() + "\n";

	return description;
}

list<Child> Game::getChildren() const {
	list<Child> playing_children = children;
	return playing_children;
}

bool Game::operator==(Game &game) const {
	auto this_it = children.begin();
	auto another_it = game.children.begin();

	while (*this_it == *another_it) {
		++this_it;
		++another_it;

		if (this_it == children.end() && another_it == game.children.end())
			return true;
	}

	return false;
}
