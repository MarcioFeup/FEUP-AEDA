#ifndef AEDA1920_FP04_UTILS_H
#define AEDA1920_FP04_UTILS_H


#include <vector>
#include <functional>

using namespace std;

/**
 * Provides tools to search in vectors.
 */
namespace search {

	/**
	 * Gets the index of a member in a function using sequential search.
	 *
	 * @tparam Comparable the type of elements of the vector
	 * @param vector the vector to search
	 * @param element the element to find
	 * @return the index of the element, or -1 if the element does not exist
	 */
	template<class Comparable>
	int sequentialSearch(const vector<Comparable> &vector, Comparable element) {
		for (int i = 0; i < vector.size(); i++)
			if (vector[i] == element)
				return i;   // found
		return -1;     // not found
	}
}

/**
 * Provides tools to sort vectors.
 */
namespace sort {

	/**
	 * Internal tools to realize the sorts.
	 */
	namespace tools {

		/**
		 * Swaps two elements in a vector.
		 *
		 * @tparam Comparable the type of elements of the vector
		 * @param vector the vector
		 * @param a the index of one element
		 * @param b the index of other element
		 */
		template<class Comparable>
		void swap(vector<Comparable> &vector, int a, int b) {
			Comparable tmp = vector[a];
			vector[a] = vector[b];
			vector[b] = tmp;
		}

		/**
		 * Gets the median of three elements in a vector.
		 *
		 * @tparam Comparable the type of elements in the vector
		 * @param vector the vector
		 * @param left the left element
		 * @param right the right element
		 * @param less_than the function that verifies if a member is less than other
		 * @return the median
		 */
		template<class Comparable>
		const Comparable &median3(vector<Comparable> &vector, int left,
								  int right, bool (*less_than)(const Comparable &, const Comparable &)) {

			int center = (left + right) / 2;

			if (less_than(vector[center], vector[left]))
				swap(vector, center, left);
			if (less_than(vector[right], vector[left]))
				swap(vector, right, left);
			if (less_than(vector[right], vector[center]))
				swap(vector, right, center);
			swap(vector, center, right - 1);
			return vector[right - 1];
		}
	}

	/**
	 * Sorts a vector using insertion sort.
	 * 
	 * @tparam Comparable the type of elements in the vector 
	 * @param vector the vector
	 * @param less_than the function that defines if a member should be more left than other
	 */
	template<class Comparable>
	void insertionSort(vector<Client> &vector, bool (*less_than)(const Comparable &, const Comparable &)) {
		for (unsigned long p = 1; p < vector.size(); p++) {
			Comparable tmp = vector[p];
			unsigned long j;
			for (j = p; j > 0 && less_than(tmp, vector[j - 1]); j--)
				vector[j] = vector[j - 1];
			vector[j] = tmp;
		}
	}

	/**
	 * Sorts a vector using quick sort.
	 * 
	 * @tparam Comparable the type of elements in the vector 
	 * @param vector the vector
	 * @param left the most left element to sort
	 * @param right the most right element to sort
	 * @param less_than the function that defines if a member should be more left than other
	 */
	template<class Comparable>
	void quickSort(vector<Comparable> &vector, int left, int right, bool (*less_than)(const Comparable &, const Comparable &)) {
		if (right - left <= 10)
			insertionSort(vector, less_than);

		else {
			Comparable x = tools::median3(vector, left, right, less_than);
			int i = left;
			int j = right - 1;

			while (i < j) {
				while (less_than(vector[++i], x));
				while (less_than(x, vector[--j]));

				if (i < j)
					tools::swap(vector, i, j);
			}

			tools::swap(vector, i, right - 1);
			quickSort(vector, left, i - 1, less_than);
			quickSort(vector, i + 1, right, less_than);
		}
	}
}


#endif //AEDA1920_FP04_UTILS_H