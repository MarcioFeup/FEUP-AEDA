#ifndef AEDA1920_FP07_WORD_H
#define AEDA1920_FP07_WORD_H


#include <string>

class Word {
  public:
	Word(const std::string &word, const std::string &meaning);

	const std::string &getWord() const;

	const std::string &getMeaning() const;

	void setMeaning(const std::string &meaning);

	bool operator<(const Word &rhs) const;

	bool operator==(const Word &rhs) const;

	friend std::ostream &operator<<(std::ostream &os, const Word &word);

  private:
	std::string word;

	std::string meaning;
};


#endif //AEDA1920_FP07_WORD_H
