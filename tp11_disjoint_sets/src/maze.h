#ifndef MAZE_H
#define MAZE_H

#include "disjointSets.h"

/**
 * Represents a maze.
 * A maze is complete whenever there exists a path that can go through all the cells in the maze, this is, all the cells
 * are in the same set.
 */
class Maze {
  public:
	/**
	 * The constructor of the maze.
	 * This create a vector where every element (cell) is the root of a set.
	 *
	 * @param rows the number of rows of the maze, only for drawing purposes
	 * @param cols the number of columns of the maze, only for drawing purposes
	 */
	Maze(int rows, int cols);

	/**
	 * Builds a random, complete, maze.
	 */
	void buildRandomMaze();

	/**
	 * Returns the disjoint sets.
	 *
	 * @return the disjoint sets
	 */
	DisjointSets getSets() const;

	/**
	 * Prints the maze in the terminal.
	 */
	void printMaze() const;

  private:
	/**
	 * The disjoint sets that implement the maze.
	 */
	DisjointSets maze;

	/**
	 * The number of rows of the maze.
	 */
	int nrows = 0;

	/**
	 * The number of columns of the maze.
	 */
	int ncols = 0;

	/**
	 * A vector that stores the pair of neighbour cells that have no walls between them, this is, that are connected.
	 */
	vector<pair<int, int>> no_walls;

	/**
	 * Gets the neighbour cells of a given cell.
	 *
	 * @param x the given cell
	 * @return the vector with the neighbour cell
	 */
	vector<int> getNeighbours(int x) const;
};

#endif
