#include "player.h"

#include <utility>

Player::Player(std::string name) : name(std::move(name)) {}

void Player::addBet(const Bet &bet) {
	bets.insert(bet);
}

unsigned Player::qtBetsOn(unsigned number) const {
	unsigned count = 0;

	for (const Bet &bet : bets)
		if (bet.has(number))
			++count;

	return count;
}

unsigned Player::getQtBets() const {
	return bets.size();
}

std::unordered_set<Bet, bet_hash, bet_equals> Player::getPrizedBets(const std::unordered_set<unsigned> &draw) const {
	const unsigned NEEDED_CORRECTS = 4;

	betting_set res;

	for (const Bet &bet : bets)
		if (bet.getCorrects(draw) >= NEEDED_CORRECTS)
			res.insert(bet);

	return res;
}
