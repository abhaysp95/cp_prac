#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using vec = std::vector<int>;

template<typename ForwardIterator>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, int key) {
	size_t len = std::distance(first, last);

	while (len > 0) {
		size_t half = len >> 1;
		ForwardIterator middle = first;
		std::advance(first, half);
		if (*middle < key) {
			first = middle;
			++first;
			len = len - half - 1;
		} else {
			len = half;
		}
	}

	return first;
}

template<typename ForwardIterator>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, int key) {
	size_t len = std::distance(first, last);

	while (len > 0) {
		size_t half = len >> 1;
		ForwardIterator middle = first;
		std::advance(middle, half);
		if (key < *middle) {
			len = half;
		} else {
			first = middle;
			++first;
			len = len - half - 1;
		}
	}

	return first;
}

int main(void) {
	vec arr{2, 2 , 3 , 3 , 3 , 3 , 4};
	int key = 3;

	// solution1
	printf("%zu\n", std::distance(
				lower_bound(arr.begin(), arr.end(), key),
				upper_bound(arr.begin(), arr.end(), key)));

	return 0;
}
