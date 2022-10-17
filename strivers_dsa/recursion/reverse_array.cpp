#include <iostream>
#include <string>

using namespace std;

#define INF 1e6

bool reverse_array(int* const arr, size_t x, size_t sz) {
	if (x >= sz - x -1) {
		return true;
	}
	// std::cout << "x: " << x << std::endl;
	std::swap(arr[x], arr[sz - x -1]);
	return reverse_array(arr, x + 1, sz);
}

// try writing the reverse_array for std::array<>

int main(void) {
	int x{};
	int arr[(unsigned long)(INF)] = { 0 };  // just for knowledge here
	size_t count{};
	while (std::cin >> arr[count++]) { }
	// std::cout << "count: " << count << std::endl;
	reverse_array(arr, 0, count - 1);
	for(size_t i = 0; i < count - 1; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}
