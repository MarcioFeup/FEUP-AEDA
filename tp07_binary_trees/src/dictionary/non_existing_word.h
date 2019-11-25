#ifndef AEDA1920_FP07_NON_EXISTING_WORD_H
#define AEDA1920_FP07_NON_EXISTING_WORD_H


#include <string>
#include "word.h"

/**
 * Represents an exception that represents a non existing word in a dictionary.
 * The exception provides access to the previous and the next word in the dictionary.
 * E.g.: Searching for "Pineappli" could throw this exception with the word "Pineapple" as the previous and "Powder" as the next.
 */
class NonExistingWord : public std::exception {
  public:
	/**
	 * Constructs the exception with the previous and the next word.
	 *
	 * @param previous_word the const reference to the previous word
	 * @param next_word the const reference to the next word
	 */
	NonExistingWord(const Word &previous_word, const Word &next_word);

	/**
	 * Returns the previous word.
	 *
	 * @return the word as a string
	 */
	std::string getPreviousWord() const;

	/**
	 * Returns the previous word's meaning.
	 *
	 * @return the previous word's meaning
	 */
	std::string getPreviousMeaning() const;

	/**
	 * Returns the next word.
	 *
	 * @return the word as a string
	 */
	std::string getNextWord() const;

	/**
	 * Returns the next word's meaning.
	 *
	 * @return the next word's meaning
	 */
	std::string getNextMeaning() const;

  private:
	/**
	 * The previous word in the dictionary.
	 */
	Word previous_word;

	/**
	 * The next word in the dictionary.
	 */
	Word next_word;
};


#endif //AEDA1920_FP07_NON_EXISTING_WORD_H
