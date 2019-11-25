#ifndef AEDA1920_FP07_DICTIONARY_H
#define AEDA1920_FP07_DICTIONARY_H


#include "word.h"
#include "../binary_tree/bst.h"

/**
 * Represents a digital dictionary.
 * A dictionary stores words implementation a binary search tree.
 */
class Dictionary {
  public:
	/**
	 * The constructor of the dictionary.
	 * Starts an empty dictionary with a "not found" word.
	 */
	Dictionary();

	/**
	 * Reads and implements the words of the dictionary given an ifstream.
	 *
	 * @param ifstream the ifstream
	 */
	void read(ifstream &ifstream);

	/**
	 * Gets the meaning of a word given the word.
	 *
	 * @param word the word to search
	 * @return the meaning of the word
	 * @throws NonExistingWord if the word does not exist
	 */
	std::string query(std::string word) const;

	/**
	 * Changes the meaning of a given word.
	 * If the word does not exist, creates it.
	 *
	 * @param word the word
	 * @param meaning the new meaning
	 * @return true if it changed the meaning successfully, false if the word didn't previously existed
	 */
	bool amend(std::string word, std::string meaning);

	/**
	 * Prints the entire dictionary to the console.
	 */
	void print() const;

	/**
	 * Returns a const binary search tree with the words of the dictionary.
	 *
	 * @return the const binary search tree
	 */
	const BST<Word> &getWords() const;

  private:
	/**
	 * The binary search tree that stores the words.
	 */
	BST<Word> words;
};

#endif //AEDA1920_FP07_DICTIONARY_H
