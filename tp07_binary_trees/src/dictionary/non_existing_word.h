#ifndef AEDA1920_FP07_NON_EXISTING_WORD_H
#define AEDA1920_FP07_NON_EXISTING_WORD_H


#include <string>
#include "word.h"

class NonExistingWord {
public:
	NonExistingWord(const Word &previousWord, const Word &nextWord);

	std::string getPreviousWord() const;

	std::string getPreviousMeaning() const;

	std::string getNextWord() const;

	std::string getNextMeaning() const;

private:
	Word previous_word;

	Word next_word;
};


#endif //AEDA1920_FP07_NON_EXISTING_WORD_H
