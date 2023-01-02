#include <iostream>

using namespace std;

#define INF 1e6

size_t remove_duplicates(int* const arr, const size_t sz) {
	if (1 == sz) return sz;
	size_t x{};
	int px{arr[x]};

	for (size_t i{1}; i < sz; i++) {
		if (px != arr[i]) {
			arr[++x] = arr[i];
			px = arr[i];
		}
	}

	return x;
}

int main(void) {
	int arr[(size_t)INF] = { '\0' };
	size_t count{};
	while (std::cin >> arr[count++]) { }
	size_t new_sz = remove_duplicates(arr, count - 1);
	for (size_t i{}; i <= new_sz; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
