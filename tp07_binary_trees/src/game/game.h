#ifndef AEDA1920_FP07_GAME_H
#define AEDA1920_FP07_GAME_H


#include "circle.h"
#include "../binary_tree/binary_tree.h"

class Game {
  public:
	Game(int level, vector<int> &scores, vector<bool> &states);

	string print();

	int play();

	int mostVisited();

	const BinaryTree<Circle> &getBoard() const;

  private:
	BinaryTree<Circle> board;

	BinaryTree<Circle> buildTree(vector<Circle> aux, int pos, int levels_left);
};


#endif //AEDA1920_FP07_GAME_H
