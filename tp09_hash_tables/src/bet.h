#ifndef AEDA1920_FP09_BET_H
#define AEDA1920_FP09_BET_H


#include <unordered_set>
#include <vector>

typedef std::unordered_set<unsigned> betting_slip;

class Bet {
  public:
	Bet();

	void build(const std::vector<unsigned> &values, unsigned qt = 6);

	bool has(unsigned num) const;

	unsigned getCorrects(const betting_slip &draw) const;

	const betting_slip &getNumbers() const;

  private:
	betting_slip numbers;
};

struct bet_hash {
	int operator()(const Bet &bet) const {
		int res = 0;

		for (int num : bet.getNumbers())
			res += 17 * num;

		return res;
	}
};

struct bet_equals {
	bool operator()(const Bet &bet1, const Bet &bet2) const {
		return bet1.getNumbers() == bet2.getNumbers();
	}
};


#endif //AEDA1920_FP09_BET_H
