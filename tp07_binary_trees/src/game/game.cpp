#include "game.h"

const BinaryTree<Circle> &Game::getBoard() const {
	return board;
}

Game::Game(int level, vector<int> &scores, vector<bool> &states) {
	vector<Circle> given_circles;

	for (int i = 0; i < scores.size(); ++i)
		given_circles.push_back(Circle(scores[i], states[i]));

	this->board = buildTree(given_circles, 0, level);
}

BinaryTree<Circle> Game::buildTree(vector<Circle> aux, int pos, int levels_left) {
	Circle circle = aux[pos];

	if (levels_left == 0)
		return BinaryTree<Circle>(circle);

	BinaryTree<Circle> left =  buildTree(aux, 2 * pos + 1, levels_left - 1);
	BinaryTree<Circle> right =  buildTree(aux, 2 * pos + 2, levels_left - 1);

	return BinaryTree<Circle>(circle, left, right);
}

string Game::to_string() {
	string res = "";

	for (BTItrLevel<Circle> it(board); !it.isAtEnd(); it.advance()) {
		res += std::to_string(it.retrieve().getScore()) + "-";
		res += (it.retrieve().isToRight()) ? "true" : "false";
		res += "-" + std::to_string(it.retrieve().getVisitCount()) + "\n";
	}

	return res;
}

int Game::play() {
	int to_reach, pos = 1;
	BTItrLevel<Circle> it(board);
	int score = 0;

	while(!it.isAtEnd()) {
		Circle &current = it.retrieve();
		score = current.getScore();
		to_reach = pos * 2;

		if (current.isToRight())
			to_reach++;

		current.changeState();
		current.addVisit();

		while (pos < to_reach && !it.isAtEnd()) {
			pos++;
			it.advance();
		}
	}

	return score;
}

int Game::mostVisited() {
	int res = 0;

	BTItrLevel<Circle> it(board);
	it.advance(); // ignore the first one
	while (!it.isAtEnd()) {
		if (it.retrieve().getVisitCount() > res)
			res = it.retrieve().getVisitCount();

		it.advance();
	}

	return res;
}
