#include "maze.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>

using namespace std;

DisjointSets Maze::getSets() const {
	return maze;
}

void Maze::printMaze() const {
	cout << endl;
	cout << setw(3) << " ";
	for (int j=0; j<ncols; j++) {
		cout << setw(6) << "______";
	}
	for (int i=0; i<nrows; i++) {
		cout << endl;
		cout << setw(3) << "|";
		for (int j=0; j<ncols-1; j++) {
			int val = i*nrows+j;
			cout << setw(3) << val<<setw(3);
			if (no_walls.empty() || find(no_walls.begin(),no_walls.end(),pair<int,int>(val,val+1)) == no_walls.end())
				cout << "|";
			else
				cout <<" ";
		}
		int val = i*nrows+ncols-1;
		cout << setw(3) << val<<setw(3) << "|";
		cout <<endl;
		cout << setw(3) << " ";
		for (int j=0; j<ncols; j++) {
			int val = i*nrows+j;
			if (i<nrows-1) {
				if ( no_walls.empty() || find(no_walls.begin(), no_walls.end(), pair<int, int>(val, val + ncols)) == no_walls.end())
					cout << setw(6) << "______";
				else
					cout << setw(6) << " ";
			} else
				cout << setw(6) << "______";
		}

	}
	cout <<endl << endl;	
}

Maze::Maze(int rows, int cols) {
	this->maze = DisjointSets(rows * cols);

	this->nrows = rows;
	this->ncols = cols;
}

vector<int> Maze::getNeighbours(int x) const {
	vector<int> res;

	bool left = true, right = true, top = true, bottom = true;

	if (x % ncols == 0 || x == 0)
		left = false;
	if ((x + 1) % ncols == 0)
		right = false;
	if (x / ncols == 0)
		top = false;
	if (x / ncols >= nrows - 1)
		bottom = false;

	if (left)
		res.push_back(x - 1);
	if (top)
		res.push_back(x - ncols);
	if (right)
		res.push_back(x + 1);
	if (bottom)
		res.push_back(x + ncols);

	return res;
}

// TODO
void Maze::buildRandomMaze() {
	srand(time(nullptr));

	while (maze.getNumberOfSets() > 1) {
		int x = rand() % (nrows * ncols);

		vector<int> neighbours = this->getNeighbours(x);
		int y = neighbours[rand() % neighbours.size()];

		while (find(no_walls.begin(), no_walls.end(), pair<int, int>(x, y)) != no_walls.end() ||
			   (find(no_walls.begin(), no_walls.end(), pair<int, int>(y, x)) != no_walls.end())) { // opposite wall

			if (x >= nrows * ncols - 1)
				x = -1;

			x++;
			neighbours = this->getNeighbours(x);
			y = neighbours[rand() % neighbours.size()];
		}

		no_walls.emplace_back(x, y);
		no_walls.emplace_back(y, x);

		if (maze.find(x) != maze.find(y))
			maze.unionSets(maze.find(x), maze.find(y));

		printMaze(); // test
	}
}

