#ifndef AEDA1920_FP04_UTILS_H
#define AEDA1920_FP04_UTILS_H


#include <vector>
#include <functional>

using namespace std;

namespace search {

	template<class Comparable>
	int sequentialSearch(const vector<Comparable> &v, Comparable x) {
		for (int i = 0; i < v.size(); i++)
			if (v[i] == x)
				return i;   // found
		return -1;     // not found
	}
}

namespace sort {

	template <class Comparable>
	void swap(vector<Comparable> &v, int a, int b) {
		Comparable tmp = v[a];
		v[a] = v[b];
		v[b] = tmp;
	}

	template <class Comparable>
	const Comparable &median3(vector<Comparable> &v, int left, int right, bool (*less_than)(Comparable, Comparable)) {
		int center = (left + right) / 2;

		if (less_than(v[center], v[left]))
			sort::swap(v, center, left);
		if (less_than(v[right], v[left]))
			sort::swap(v, right, left);
		if (less_than(v[right], v[center]))
			sort::swap(v, right, center);
		sort::swap(v, center, right - 1);
		return v[right - 1];
	}

	template<class Comparable>
	void insertionSort(vector<Client> &v, bool (*less_than)(Comparable, Comparable)) {
		for (unsigned int p = 1; p < v.size(); p++) {
			Comparable tmp = v[p];
			int j;
			for (j = p; j > 0 && less_than(tmp, v[j - 1]); j--)
				v[j] = v[j - 1];
			v[j] = tmp;
		}
	}

	template<class Comparable>
	void quickSort(vector<Comparable> &v, int left, int right, bool (*less_than)(Comparable, Comparable)) {
		if (right - left <= 10)
			insertionSort(v, less_than);

		else {
			Comparable x = median3(v, left, right, less_than);
			int i = left;
			int j = right - 1;

			while (i < j) {
				while (less_than(v[++i], x));
				while (less_than(x, v[--j]));

				if (i < j)
					swap(v, i, j);
			}

			swap(v, i, right - 1);
			quickSort(v, left, i - 1, less_than);
			quickSort(v, i + 1, right, less_than);
		}
	}
}

namespace math {
}

#endif //AEDA1920_FP04_UTILS_H
