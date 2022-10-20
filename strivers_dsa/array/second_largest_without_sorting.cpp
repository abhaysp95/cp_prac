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

int main(void) {
	int arr[(size_t)INF] = { '\0' };
	size_t count = 0;
	while (std::cin >> arr[count++]) { }
	std::cout << second_largest(arr, count - 1) << std::endl;
	std::cout << second_smallest(arr, count - 1) << std::endl;
	return 0;
}
