#ifndef AEDA1920_FP09_PLAYER_H
#define AEDA1920_FP09_PLAYER_H


#include "bet.h"

typedef std::unordered_set<Bet, bet_hash, bet_equals> betting_set;

/**
 * Represents an actor that has bets.
 */
class Player {
  public:
	/**
	 * The constructor of the player that initializes it with no bets.
	 *
	 * @param name the name of the player
	 */
	explicit Player(std::string name = "anonymous");

	/**
	 * Adds a bet.
	 *
	 * @param bet the bet
	 */
	void addBet(const Bet &bet);

	/**
	 * Gets the amount of bets of the player that have a given number
	 *
	 * @param number the given number
	 * @return the amount of bets
	 */
	unsigned qtBetsOn(unsigned number) const;

	/**
	 * Gets the winner bets given a draw.
	 * A winner bet is a bet that has more than a minimum required correct numbers.
	 *
	 * @param draw the draw
	 * @return a set with the bets
	 */
	betting_set getPrizedBets(const betting_slip &draw) const;

	/**
	 * Gets the amount of bets of the player.
	 *
	 * @return the amount of bets
	 */
	unsigned getQtBets() const;

  private:
	/**
	 * The name of the player.
	 */
	std::string name;

	/**
	 * The bets of the player stored in an unordered_set.
	 */
	betting_set bets;
};


#endif //AEDA1920_FP09_PLAYER_H
