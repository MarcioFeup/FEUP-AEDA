#ifndef AEDA1920_FP09_PLAYER_H
#define AEDA1920_FP09_PLAYER_H


#include "bet.h"

typedef std::unordered_set<Bet, bet_hash, bet_equals> betting_set;

class Player {
  public:
	explicit Player(std::string name = "anonymous");

	void addBet(const Bet &bet);

	unsigned qtBetsOn(unsigned number) const;

	betting_set getPrizedBets(const betting_slip &draw) const;

	unsigned getQtBets() const;

  private:
	std::string name;

	betting_set bets;
};


#endif //AEDA1920_FP09_PLAYER_H
