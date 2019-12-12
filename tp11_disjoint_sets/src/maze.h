#ifndef MAZE_H
#define MAZE_H

#include "disjointSets.h"

class Maze {
  public:
	Maze(int rows, int cols);

	void buildRandomMaze();

	DisjointSets getSets() const;

	void printMaze() const;

  private:
	DisjointSets maze;

	int nrows = 0;

	int ncols = 0;

	vector<pair<int, int>> no_walls;

	vector<int> getNeighbours(int x) const;
};

#endif
