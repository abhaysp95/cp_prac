#include <iostream>
#include <unordered_map>

using namespace std;

#define INF 1e6

std::unordered_map<int, int> count_frequency(const int* const arr, size_t sz) {
	std::unordered_map<int, int> umap{};
	for (size_t i = 0; i < sz; i++) {
		umap[arr[i]]++;
	}

	return umap;
}

// for approach with O(n) (using another array), there are two ways, use new_arr[arr[i]]++ or use two loops
//
// find the highest/lowest frequency count can be easily done with map (as used here)


int main(void) {
	int arr[(size_t)INF] = {'\0'};
	size_t count{};
	while (std::cin >> arr[count++]) { }
	std::unordered_map<int, int> res = count_frequency(arr, count -1);
	for (const std::pair<int, int>& x: res) {
		std::cout << x.first << ", " << x.second << '\n';
	}
	return 0;
}
