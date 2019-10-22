#ifndef AEDA1920_FP05_GAME_H
#define AEDA1920_FP05_GAME_H

#include <list>
#include "child.h"

/**
 * Represents a portuguese children's game.
 * “Pim Pam Pum cada bola mata um pra galinha e pro peru quem se livra és mesmo tu”
 *
 * This game lies in 3 rules:
 *     <p>* The first child says the above sentence, walking through the words, points to other children, in a list, successively.</p>
 *     <p>* At the end of the sentence, the child that is being pointed, is freed and gets out of the game. The sentence restarts
 * in the next child.</p>
 *     <p>* The last remaining child looses the game.</p>
 *
 * @author Márcio Duarte
 */
class Game {

  public:

	/**
	 * Constructs the game without any child.
	 */
	Game();

	/**
	 * Constructs the game with an already filled list of children.
	 *
	 * @param children
	 */
	explicit Game(std::list<Child> &children);

	/**
	 * Returns the amount of words in a sentence.
	 *
	 * @param sentence the sentence
	 * @return the amount of words
	 */
	static unsigned qtWords(std::string sentence);

	/**
	 * Adds a child the to game.
	 *
	 * @param child the child
	 */
	void addChild(const Child &child);

	/**
	 * Inverts the order of the children.
	 *
	 * @return the list of children
	 */
	std::list<Child> &reverse();

	/**
	 * Removes the children with an age above a given one from the game.
	 *
	 * @param age the given age
	 * @return a list with the children that were removed
	 */
	std::list<Child> divide(unsigned age);

	/**
	 * Plays through the game with a sentence, returning the child who lost.
	 *
	 * @param sentence the sentence
	 * @return the child who lost
	 */
	Child &whoLooses(std::string sentence);

	/**
	 * Sets a list of children in the game.
	 *
	 * @param children the list of children
	 */
	void setChildren(const std::list<Child> &children);

	/**
	 * Returns a new list of children with their order shuffled, keeping the initial list unaltered.
	 *
	 * @return the new list
	 */
	std::list<Child> shuffle() const;

	/**
	 * Gets a string with information on all the children currently playing.
	 *
	 * @return the string
	 */
	std::string describe() const;

	/**
	 * Returns the list of children currently in the game.
	 *
	 * @return the list
	 */
	std::list<Child> getChildren() const;

	/**
	 * Compares this game with another one.
	 * Two games are considered equal if they share the same children in the same order.
	 *
	 * @param game the other game to compare
	 * @return true if the games are equal, false otherwise
	 */
	bool operator==(Game &game) const;

  private:
	std::list<Child> children;
};


#endif //AEDA1920_FP05_GAME_H
