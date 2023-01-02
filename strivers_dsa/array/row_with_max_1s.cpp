#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using vec = std::vector<int>;
using vvec = std::vector<std::vector<int>>;
using vec_citer = std::vector<int>::const_iterator;
using vvec_citer = std::vector<std::vector<int>>::const_iterator;

// get the lower bound (returns iterator)
template<typename ForwardIterator>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, int value) {

	vec::difference_type len = std::distance(first, last);

	while (len > 0) {
		vec::difference_type half = len >> 1;
		ForwardIterator middle = first;
		std::advance(middle, half);
		if (*middle < value) {
			first = middle;
			++first;
			len = len - half - 1;
		} else {
			len = half;
		}
	}

	return first;
}

/** for each row, find the index of 1 (lower bound) and subtract it with len of
 * that row */
// returns 0 based index of row
size_t row_with_max_1(const vvec& mat) {
	size_t row = 0, max_one = 0;

	vvec_citer citer = mat.cbegin();
	while (citer != mat.cend()) {
		vec_citer first_one = lower_bound(citer->cbegin(), citer->cend(), 1);
		vec::difference_type total_one = std::distance(first_one, citer->cend());
		if (max_one < total_one) {
			row = std::distance(mat.cbegin(), citer);
			max_one = total_one;
		}
		citer++;
	}

	return row;
}

int main(void) {
	vvec matrix = {
		{0, 1, 1, 1},
		{0, 0, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 0, 0}};
	/* vvec matrix = {
		{0, 0},
		{1, 1}}; */

	printf("row: %zu\n", row_with_max_1(matrix));

	return 0;
}

	// vec arr = {0, 1, 1, 1};

	// printf("%zu\n", std::lower_bound(arr.cbegin(), arr.cend(), 1) - arr.cbegin());
