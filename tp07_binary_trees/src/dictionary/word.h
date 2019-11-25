#ifndef AEDA1920_FP07_WORD_H
#define AEDA1920_FP07_WORD_H


#include <string>

/**
 * Represents a word, providing access to the word as a string and its meaning.
 */
class Word {
  public:
	/**
	 * The constructor of the word.
	 *
	 * @param word the const reference to the word as a string
	 * @param meaning the const reference to the meaning of the word
	 */
	Word(const std::string &word, const std::string &meaning);

	/**
	 * Gets the word as a string.
	 *
	 * @return the const reference to the word
	 */
	const std::string &getWord() const;

	/**
	 * Gets the meaning of the word.
	 *
	 * @return the const reference to the meaning
	 */
	const std::string &getMeaning() const;

	/**
	 * Sets the meaning of the word.
	 *
	 * @param meaning the const reference to the meaning
	 */
	void setMeaning(const std::string &meaning);

	/**
	 * Compares with another word.
	 * The comparison is made comparing alphabetically the words.
	 *
	 * @param rhs the const reference to the other word
	 * @return true if this is word is "lower" than the other, false otherwise
	 */
	bool operator<(const Word &rhs) const;

	/**
	 * Verifies if another word is equal to this one.
	 * The comparision does not take the meaning into account.
	 *
	 * @param rhs the other word
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Word &rhs) const;

	/**
	 * Prints a word in a ostream.
	 *
	 * @param os the ostream
	 * @param word the word
	 * @return the changed ostream
	 */
	friend std::ostream &operator<<(std::ostream &os, const Word &word);

  private:
	/**
	 * The word as a string.
	 */
	std::string word;

	/**
	 * The meaning of the word.
	 */
	std::string meaning;
};


#endif //AEDA1920_FP07_WORD_H
