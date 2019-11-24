#include <iostream>
#include "word.h"

Word::Word(const std::string &word, const std::string &meaning) : word(word), meaning(meaning) {}

const std::string &Word::getWord() const {
	return word;
}

const std::string &Word::getMeaning() const {
	return meaning;
}

void Word::setMeaning(const std::string &meaning) {
	Word::meaning = meaning;
}

bool Word::operator<(const Word &rhs) const {
	return word < rhs.word;
}

std::ostream &operator<<(std::ostream &os, const Word &word) {
	os << word.word << std::endl <<
	   word.meaning << std::endl;
}

bool Word::operator==(const Word &rhs) const {
	return word == rhs.word;
}

