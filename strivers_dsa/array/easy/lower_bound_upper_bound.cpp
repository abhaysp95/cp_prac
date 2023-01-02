#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// key itself or the least greater than key (immediate next greater for key)
template<typename _ForwardIterator>
_ForwardIterator lower_bound(_ForwardIterator first, _ForwardIterator last, int key) {
	// typedef typename std::iterator_traits<_ForwardIterator>::distance_type _Distance_type;

	size_t len = std::distance(first, last);

	while (len > 0) {
		size_t half = len >> 1;
		_ForwardIterator middle = first;
		std::advance(middle, half);
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

// immediate next to key (least greater than key), not the key itself (if present)
template<typename _ForwardIterator>
_ForwardIterator upper_bound(_ForwardIterator first, _ForwardIterator last, int key) {

	size_t len = std::distance(first, last);

	while (len > 0) {
		size_t half = len >> 1;
		_ForwardIterator middle = first;
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
	std::vector<int> vec = {10, 11, 16, 20};
	int key = 0;
	scanf("%d", &key);
	std::vector<int>::iterator liter = lower_bound(vec.begin(), vec.end(), key);
	std::vector<int>::iterator uiter = upper_bound(vec.begin(), vec.end(), key);
	printf("%d\n", (vec.end() != liter) ? *liter : -1);
	printf("%d\n", (vec.end() != uiter) ? *uiter : -1);

	return 0;
}
