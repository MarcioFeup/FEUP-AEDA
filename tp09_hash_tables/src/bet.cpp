#include "bet.h"

Bet::Bet() = default;

const betting_slip &Bet::getNumbers() const {
	return numbers;
}

void Bet::build(const std::vector<unsigned> &values, unsigned int qt) {
	unsigned count = 0;

	for (auto it = values.begin(); it != values.end() && count < qt; ++it) {
		auto pair = numbers.insert(*it);

		if (pair.second)
			count ++;
	}
}

bool Bet::has(unsigned num) const {
	return numbers.find(num) != numbers.end();
}

unsigned Bet::getCorrects(const betting_slip &draw) const {
	unsigned count = 0;

	for (int number : draw)
		if (this->has(number))
			++count;

	return count;
}
