#include <algorithm>
#include <iostream>
#include <iterator>

template<typename ForwardIterator>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, int key) {
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

	return first;
}

template<typename ForwardIterator>
int binary_search(ForwardIterator first, ForwardIterator last, int key) {

	ForwardIterator lb = lower_bound(first, last, key);
	if (lb != last && !(*lb > key)) {
		return std::distance(first, lb);
	}

	return -1;
}

// iterative (in general you wouldn't return -1)
bool find_x(int * const arr, int sz, int key) {

	int min = 0, max = sz - 1;
	while (min <= max) {
		int mid = (min + max) / 2;
		if (key == arr[mid]) {
			return true;
		}
		if (key > arr[mid]) {
			min = mid + 1;
		} else {
			max = mid;
		}
	}

	return false;
}

// recursive
bool find_x_recursive(int *const arr, int max, int min, int key) {
	if (min > max) {
		return false;
	}
	int mid = (min + max) / 2;
	if (key == arr[mid]) {
		return true;
	} else if (min == max) return false;  // no more recursive calls necessary

	if (key > arr[mid]) {
		return find_x_recursive(arr, max, mid + 1, key);
	} else {
		return find_x_recursive(arr, mid, min, key);
	}
}


int main(void) {
	int arr[] = {1, 2, 3, 5, 6, 7};
	size_t sz = sizeof(arr) / sizeof(int);
	int key;
	scanf("%d", &key);
	// printf("%d\n", find_x(arr, sz, key));
	// printf("%d\n", find_x_recursive(arr, sz - 1, 0, key));
	printf("%d\n", binary_search(std::begin(arr), std::end(arr), key));

	return 0;
}
