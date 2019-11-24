#ifndef AEDA1920_FP07_DICTIONARY_H
#define AEDA1920_FP07_DICTIONARY_H


#include "word.h"
#include "../binary_tree/bst.h"

class Dictionary {
  public:
	Dictionary();

	void read(ifstream &ifstream);

	std::string query(std::string word) const;

	bool amend(std::string word, std::string meaning);

	void print() const;

	const BST<Word> &getWords() const;

  private:
	BST<Word> words;
};

#endif //AEDA1920_FP07_DICTIONARY_H
