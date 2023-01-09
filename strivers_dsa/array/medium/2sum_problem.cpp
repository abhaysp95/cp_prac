#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using vec = std::vector<int>;

struct sum_idx {
	size_t first;
	size_t last;
};

void print_arr(const vec& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d\n", arr[arr.size() - 1]);
}


/** two pointer method */
// other than brute force this is another easy method
sum_idx solution1(const vec& arr, int target) {
	vec temp = arr;  // deep copy happens
	sum_idx res{};

	std::sort(temp.begin(), temp.end());

	int i = 0, j = arr.size() - 1;
	while (i < j) {
		int sum = temp[i] + temp[j];
		if (sum == target) {
			res.first = i, res.last = j;
		}

		if (sum < target) {
			i++;
		} else {
			j--;
		}

		// find the idx
		/* auto my_lambda = [&](size_t find_idx) {
			for (size_t k = 0; k < arr.size(); k++) {
				if (arr[k] == temp[find_idx]) {
					return k;
				}
			}
		}; */

	}

	/* print_arr(temp);
	printf("[%d, %d]\n", i, j); */
	for (size_t k = 0; k < arr.size(); k++) {
		if (arr[k] == temp[i]) {
			res.first = k;
		} else if (arr[k] == temp[j]) {
			res.last = k;
		}
	}

	return res;
}

/** using hash structure */
// you can use hash data structure directly instead of vec, so I'm not
// considering space complexity here */
sum_idx solution2(const vec& arr, int target) {
	std::unordered_map<int, size_t> thash;
	sum_idx res{};

	for (size_t i = 0; i < arr.size(); i++) {
		if (thash.find(target - arr[i]) != thash.end()) {
			res.first = i;
			res.last = thash[target - arr[i]];

			break;
		}
		thash[arr[i]] = i;
	}

	return res;
}

int main(void) {
	/* vec arr = {2, 7, 11, 15};
	int target = 9; */
	vec arr = {3, 2, 4, 6};
	int target = 6;

	sum_idx res = solution2(arr, target);
	printf("[%zu, %zu]\n", res.first, res.last);

	return 0;
}
