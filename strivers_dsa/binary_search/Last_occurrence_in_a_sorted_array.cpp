#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using vec = std::vector<int>;

// works
long solution1(const vec& arr, int key) {
	vec::const_iterator first_occurance = std::lower_bound(arr.begin(), arr.end(), key);
	size_t first_pos = std::distance(arr.begin(), first_occurance);

	if (first_occurance != arr.cend()
			&& *first_occurance == key) {
		for (size_t i{first_pos}; i < arr.size(); i++) {
			if (arr[i] != key) {
				return i - 1;
			}
		}
	}

	return -1;
}

// same as soltuion1 (works)
long solution2(const vec& arr, int key) {
	vec::const_iterator first_occurance = std::lower_bound(arr.begin(), arr.end(), key);
	size_t first_pos = std::distance(arr.begin(), first_occurance);

	if (first_occurance != arr.cend()
			&& *first_occurance == key) {
		while (first_occurance != arr.cend()) {
			if (*first_occurance != key) {
				return std::distance(arr.begin(), first_occurance) - 1;
			}
			++first_occurance;
		}
	}

	return -1;
}

// use lower_bound for (key + 1), and return pos - 1
long solution3(const vec& arr, int key) {
	vec::const_iterator lb = std::lower_bound(arr.begin(), arr.end(), key + 1);
	size_t lb_pos = std::distance(arr.begin(), lb) - 1;

	return arr[lb_pos] == key ? lb_pos : -1;
}

// solution4 (directly)
long solution4(const vec& arr, int key) {
	int start = 0;
	int end = arr.size() - 1;
	int res = -1;

	while (start <= end) {
		int half = start + (end - start) / 2;
		if (arr[half] == key) {
			res = half;
			start = half + 1;
		} else if (arr[half] < key) {
			start = half + 1;
		} else {
			end = half - 1;
		}
	}

	return res;
}

int main(void) {
	vec arr{3,4,13,13,13,20,40};
	int key;

	scanf("%d", &key);
	printf("last occurance: %ld\n", solution3(arr, key));

	return 0;
}
