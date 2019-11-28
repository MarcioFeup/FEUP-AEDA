#ifndef AEDA1920_FP09_BET_H
#define AEDA1920_FP09_BET_H


#include <unordered_set>
#include <vector>

typedef std::unordered_set<unsigned> betting_slip;

/**
 * Represents a bet. A bet contains a hash table in the form of unordered_set of unsigned, this is, the numbers of the bet.
 */
class Bet {
  public:
	/**
	 * Constructs a new empty bet.
	 */
	Bet();

	/**
	 * Fulfills the bet with a given amount of numbers from a vector.
	 *
	 * @param values the vector of numbers
	 * @param qt the amount of numbers to add
	 */
	void build(const std::vector<unsigned> &values, unsigned qt = 6);

	/**
	 * Verifies if the vet has a given number.
	 *
	 * @param num the given number
	 * @return true if the bet has the number, false otherwise
	 */
	bool has(unsigned num) const;

	/**
	 * Gets the amount of correct numbers, given a draw.
	 *
	 * @param draw the draw
	 * @return the amount of correct numbers
	 */
	unsigned getCorrects(const betting_slip &draw) const;

	/**
	 * Gets the numbers of the bet.
	 *
	 * @return the number
	 */
	const betting_slip &getNumbers() const;

  private:
	/**
	 * The numbers of the bet in an unsigned_set
	 */
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
