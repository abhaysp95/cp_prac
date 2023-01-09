#include <iostream>
#include <algorithm>
#include <iterator>

#define INF 1e6

// problem is similar to finding floor of number
// floor: is maximum number equals to or small to X

int find_floor(int *const arr, int sz, int key) {
	int min = 0, max = sz;
	while (sz > 0) {
		int half = sz >> 1;
		int mid = arr[min + half];
		if (mid < key) {
			min = half + 1;
			sz = sz - half - 1;
		} else {
			sz = half;
		}
	}

	return arr[min];
}

// return the index (0 based)
int find_floor_stl(int *const arr, int sz, int key) {

	return std::lower_bound(arr, arr + sz, key) - arr;

	/* int min = 0, max = sz - 1;
	int fidx = 0, fele = -INF;
	while (min <= max) {
		int mid = (min + max) / 2;
		if (key == arr[mid]) {
			return mid;
		}
		if (key < arr[mid]) {
			if (0 == mid) return -1;
			max = mid;
		} else {
			if (fele < key) {
				fele = key;
			}
			min = mid + 1;
		}
	}

	return -1;  // should never come here */
}

int main(void) {
	int arr[] = { 1,2,8,10,11,12,19 };
	int sz = sizeof(arr) / sizeof(int);
	int key = 0;
	scanf("%d", &key);
	printf("%d\n", find_floor(arr, sz, key));
	printf("%d\n", find_floor_stl(arr, sz, key));
	return 0;
}
