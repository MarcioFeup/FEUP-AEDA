#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

#include <vector>

using namespace std;

class DisjointSets {
  public:
	DisjointSets();

	explicit DisjointSets(int n);

	int find(int v) const;

	void unionSets(int root1, int root2);

	int getNumberOfSets() const;

  private:
	static const int EMPTY_SET;

	vector<int> set;
};

#endif
