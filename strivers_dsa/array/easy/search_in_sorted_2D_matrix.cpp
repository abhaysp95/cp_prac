#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using vec = std::vector<int>;
using vvec = std::vector<std::vector<int>>;

// works (little normal impl of below implemented low_bound binary search)
bool bin_search(const vec& arr, int key) {

	size_t sz = arr.size();
	int min = 0;

	while (sz > 0) {
		size_t half = sz >> 1;
		int mid = arr[min + half];
		if (mid < key) {
			min = min + half + 1;
			sz = sz - half - 1;
		} else {
			sz = half;
		}
	}

	int lb = arr[min];
	return !(key < arr[min]);
}

// implemented shamelessly from std algorithm
// low_bound => number which is equal to key or smallest number which is greater than key
vec::const_iterator low_bound(vec::const_iterator& first, vec::const_iterator& last, int key) {
	size_t len = std::distance(first, last);

	while (len > 0) {
		size_t half = len >> 1;
		vec::const_iterator mid = first;
		std::advance(mid, half);
		if (*mid < key) {
			first = mid;
			++first;
			len = len - half - 1;
		} else {
			len = half;
		}
	}

	return first;
}

bool bin_search(vec::const_iterator first, vec::const_iterator last, int key) {

	vec::const_iterator iter = low_bound(first, last, key);
	return iter != last && !(key < *iter);

}

bool my_approach(const vvec& container, int key) {
	vvec::size_type i = 0;
	for (vvec::size_type i = 0; i < container.size(); i++) {
		vvec::size_type sz = container[i].size();
		if (container[i][0] < key
				&& container[i][sz - 1] >= key) {
			// return std::binary_search(container[i].begin(), container[i].end(), key);
			// return bin_search(container[i].begin(), container[i].end(), key);
			// return binary_search(container[i], key);
			return bin_search(container[i], key);
		}
	}

	return false;
}

int main(void) {
	vvec container = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
	int key = 0;
	scanf("%d", &key);

	printf("%s\n", my_approach(container, key) ? "true" : "false");

	return 0;
}
