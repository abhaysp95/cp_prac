#include <bits/stdc++.h>

using namespace std;

// the algorithm with most "off by 1" error
bool binary_search_iterative(const vector<int>& arr, const int key) {
	size_t start{}, end{arr.size()};  // start is inclusive, end is exclusive

	while (start < end) {  // as said, start is inclusive, end is exclusive
		size_t mid = start + ((end - start) / 2);  // advance by half
		if (arr[mid] == key) {
			return true;
		} else if (key > arr[mid]) {
			start = mid + 1;
		} else {
			end = mid;  // exclusive
		}
	}

	return false;
}

int main(void) {
	const vector<int> arr = {10, 30, 40, 50, 60};

	cout << (binary_search_iterative(arr, 30) ? "true" : "false") << '\n';
	cout << (binary_search_iterative(arr, 20) ? "true" : "false") << '\n';
	cout << (binary_search_iterative(arr, 50) ? "true" : "false") << '\n';


	return 0;
}
