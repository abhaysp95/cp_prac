#include <iostream>
#include <vector>

using vec = std::vector<int>;

// just follow the greater and you'll reach peak
size_t peak_idx(const vec& arr) {
	size_t first{}, last{arr.size() - 1};
	size_t last_idx = last;

	while (first < last) {
		size_t half = first + ((last - first) >> 1);

		// For the first and last element, it is enough to look at its only one neighbour.
		if (0 == half) {
			return arr[0] >= arr[1] ? arr[0] : arr[1];
		}

		if (arr.size() - 1 == half) {
			return arr[last_idx] >= arr[last_idx - 1] ? arr[last_idx] : arr[last_idx - 1];
		}

		// if it's mid element and matched
		if (arr[half] >= arr[half - 1] && arr[half] >= arr[half + 1]) {
			return arr[half];
		}

		/* if ((0 == half && arr[half] >= arr[half + 1])
				|| (arr.size() - 1 == half && arr[half - 1] <= arr[half])
				|| (arr[half] >= arr[half - 1] && arr[half] >= arr[half + 1])) {
			return half;
		} */

		// move to greater side
		if (arr[half - 1] > arr[half]) {
			last = half - 1;
		} else {
			first = half + 1;
		}

	}

	return 0;
}

int main(void) {
	vec arr{3, 5, 4, 1, 1};
	// vec arr{2,6,3,7,8,9};

	printf("%d\n", arr.at(peak_idx(arr)));

	return 0;
}
