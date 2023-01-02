#include <iostream>

using namespace std;

#define INF 1e6

int second_largest(const int* const arr, size_t sz) {
	if (1 == sz) return arr[0];
	int max = -INF, smax = -INF;
	for (size_t i = 0; i < sz; i++) {
		if (max < arr[i]) {
			smax = max;
			max = arr[i];
		}
		if (smax < arr[i] && max > arr[i]) {
			smax = arr[i];
		}
	}

	return smax;
}

int second_smallest(const int* const arr, size_t sz) {
	if (1 == sz) return arr[0];
	int min = INF, smin = INF;
	for (size_t i = 0;i < sz; i++) {
		if (min > arr[i]) {
			smin = min;
			min = arr[i];
		}
		if (smin > arr[i] && min < arr[i]) {
			smin = arr[i];
		}
	}

	return smin;
}
// you can combine the above two here

// another approach (no sorting still), combining both second largest and second
// smallest isn't the concern
std::pair<int, int> second_smallest_and_largest(const int* const arr, size_t sz) {
	int min = INF, smin = INF;
	int max = -INF, smax = -INF;
	for (size_t i{}; i < sz; i++) {
		min = std::min(min, arr[i]);
		max = std::max(max, arr[i]);
	}
	for (size_t i{}; i < sz; i++) {
		if (arr[i] < smin && min < arr[i]) {  // can also give min != arr[i]
			smin = arr[i];
		}
		if (arr[i] > smax && max > arr[i]) {  // can also give max != arr[i]
			smax = arr[i];
		}
	}

	return std::make_pair(smin, smax);
}

int main(void) {
	int arr[(size_t)INF] = { '\0' };
	size_t count = 0;
	while (std::cin >> arr[count++]) { }
	/* std::cout << second_largest(arr, count - 1) << std::endl;
	std::cout << second_smallest(arr, count - 1) << std::endl; */

	std::pair<int, int> res = second_smallest_and_largest(arr, count - 1);
	std::cout << res.first << ", " << res.second << std::endl;
	return 0;
}
