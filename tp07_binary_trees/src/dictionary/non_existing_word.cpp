#include "non_existing_word.h"

NonExistingWord::NonExistingWord(const Word &previous_word, const Word &next_word) :
		previous_word(previous_word), next_word(next_word) {}

std::string NonExistingWord::getPreviousWord() const {
	return previous_word.getWord();
}

std::string NonExistingWord::getPreviousMeaning() const {
	return previous_word.getMeaning();
}

std::string NonExistingWord::getNextWord() const {
	return next_word.getWord();
}

std::string NonExistingWord::getNextMeaning() const {
	return next_word.getMeaning();
}

