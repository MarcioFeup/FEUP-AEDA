#include "non_existing_word.h"

NonExistingWord::NonExistingWord(const Word &previousWord, const Word &nextWord) :
		previous_word(previousWord), next_word(nextWord) {}

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

