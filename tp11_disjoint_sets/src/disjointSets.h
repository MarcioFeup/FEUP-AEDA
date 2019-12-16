#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H

#include <vector>

using namespace std;

/**
 * Represents a collection of disjoint sets of ints.
 */
class DisjointSets {
  public:
	/**
	 * Constructs a collection by default.
	 */
	DisjointSets();

	/**
	 * Constructs a collection with a given number of elements.
	 *
	 * @param n the number of elements
	 */
	explicit DisjointSets(int n);

	/**
	 * Finds the root of the set in which a given element belongs.
	 *
	 * @param v the given element
	 * @return the root of the set of the given element
	 */
	int find(int v) const;

	/**
	 * Unites two sets given their root.
	 * The union is made connecting the second root with the first one, this is, the root of the second set will be
	 * assigned to the root of the first set.
	 *
	 * E.g.: [-1, 2, -1, -1, 3]
	 *         0  1  2   3  4
	 * unionSets(3, 2), then
	 *       [-1, 2, -1, 2, 3]
	 *
	 * @param root1 the root of the fist set
	 * @param root2 the root of the second set
	 */
	void unionSets(int root1, int root2);

	/**
	 * Returns the number of sets in the collection, this is the number of cells that are connected.
	 *
	 * @return the number of sets
	 */
	int getNumberOfSets() const;

  private:
	/**
	 * The int that indicates that a node is the root of the set.
	 */
	static const int EMPTY_SET;

	/**
	 * The vector that stores the sets.
	 */
	vector<int> set;
};

#endif
