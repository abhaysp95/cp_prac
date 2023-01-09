#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using vec = std::vector<int>;

template<typename ForwardIterator>
size_t lower_bound_pos(ForwardIterator first, ForwardIterator last, int key) {
	ForwardIterator temp_first = first;  // first is changed (not what it points, but where it points)
	size_t len = std::distance(first, last);

	while (len > 0) {
		size_t half = len >> 1;
		ForwardIterator middle = first;
		std::advance(middle, half);
		if (*middle < key) {
			first = middle;
			++first;
			len = len - half - 1;
		} else {
			len = half;
		}
	}

	return std::distance(temp_first, first);
}

int main(void) {
	vec arr{1, 3, 5, 6};
	int key{};

	scanf("%d", &key);

	// solution1
	/* printf("pos: %zu\n", std::distance(arr.begin(),
				std::lower_bound(arr.begin(), arr.end(), key))); */

	printf("pos: %zu\n", lower_bound_pos(arr.begin(), arr.end(), key));

	return 0;
}
