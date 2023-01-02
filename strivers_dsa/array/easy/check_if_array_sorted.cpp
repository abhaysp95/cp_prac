#include <iostream>

using namespace std;

#define INF 1e6

bool is_sorted_increasing(const int* const arr, size_t sz) {
	for (size_t i{}; i < sz - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

bool is_sorted_decreasing(const int* const arr, size_t sz) {
	for (size_t i{}; i < sz - 1; i++) {
		if (arr[i] < arr[i + 1])
			return false;
	}
	return true;
}

bool is_array_sorted(const int* const arr, size_t sz) {
	if (1 == sz) return true;
	return is_sorted_increasing(arr, sz) || is_sorted_decreasing(arr, sz);
}

int main(void) {
	int arr[(size_t)INF] = { '\0' };
	size_t count{};
	while (std::cin >> arr[count++]) { }
	std::cout << (is_array_sorted(arr, count - 1) ? "true" : "false") << std::endl;
	return 0;
}
