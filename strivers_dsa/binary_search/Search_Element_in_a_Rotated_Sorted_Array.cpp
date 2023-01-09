#include <iostream>
#include <vector>

using vec = std::vector<int>;

int search(const vec& arr, int key) {
	int first{}, last{static_cast<int>(arr.size() - 1)};

	while (first <= last) {
		int half = (first + last) >> 1;

		if (arr[half] == key) {
			return half;
		}

		if (arr[first] <= arr[half]) {  // first half is sorted, search there
			if (arr[first] <= key && arr[half] >= key) {  // key is in first half
				last = half - 1;
			} else {  // move to second half
				first = half + 1;
			}
		} else {  // first half is not sorted
			if (arr[half] <= key && key <= arr[last]) { // key is in second half
				first = half + 1;
			} else {
				last = half - 1;
			}
		}
	}

	return -1;
}

int main(void) {
	vec arr{4,5,6,7,-1,1,2,3};

	printf("%d\n", search(arr, 0));
	return 0;
}
