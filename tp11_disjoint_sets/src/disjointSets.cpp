#include "disjointSets.h"

const int DisjointSets::EMPTY_SET = -1;

DisjointSets::DisjointSets() = default;

// create n disjoint sets (one for each item)
DisjointSets::DisjointSets(int n) {
	for (int i = 0; i < n; i++)
		set.push_back(EMPTY_SET);
}

// Find the root of the set in which element v belongs
int DisjointSets::find(int v) const {
	if (set[v] < 0)
		return v;
	return find(set[v]);
}

// Perform Union of two subsets
void DisjointSets::unionSets(int root1, int root2) {
	set[root2] = root1;
}

int DisjointSets::getNumberOfSets() const {
	int count = 0;

	for (int i : set)
		if (i == EMPTY_SET)
			++count;

	return count;
}

