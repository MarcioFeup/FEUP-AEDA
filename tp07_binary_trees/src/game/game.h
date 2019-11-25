#ifndef AEDA1920_FP07_GAME_H
#define AEDA1920_FP07_GAME_H


#include "circle.h"
#include "../binary_tree/binary_tree.h"

/**
 * Represents a game that stores a board of circles, as a binary trees, where players throw balls at and those slide until a leaf circle.
 * The score of the player corresponds to the score of the leaf.
 */
class Game {
  public:
	/**
	 * Constructs a game.
	 *
	 * @param level the amount of levels in the tree (board)
	 * @param scores the scores of the circles
	 * @param states the left/right states of the circles
	 */
	Game(int level, vector<int> &scores, vector<bool> &states);

	/**
	 * Gets the game as a descriptive string.
	 *
	 * @return the descriptive string
	 */
	string to_string();

	/**
	 * Plays a single play, throwing a ball in the board.
	 *
	 * @return the score
	 */
	int play();

	/**
	 * Gets the number of visits of the most visited circle, ignoring the root.
	 *
	 * @return the number of visits
	 */
	int mostVisited();

	/**
	 * Gets the binary tree that functions as the board.
	 *
	 * @return the const reference to the board
	 */
	const BinaryTree<Circle> &getBoard() const;

  private:
	/**
	 * The binary tree that functions as the game board.
	 */
	BinaryTree<Circle> board;

	/**
	 * Builds the tree.
	 *
	 * @param aux the vector of circles
	 * @param pos the pos to build on
	 * @param levels_left the number of levels left to build
	 * @return the built tree
	 */
	BinaryTree<Circle> buildTree(vector<Circle> aux, int pos, int levels_left);
};


#endif //AEDA1920_FP07_GAME_H
