#include <iostream>
#include <vector>

#define INF 1e6

using vec = std::vector<int>;

struct res_idx {
	size_t first;
	size_t last;
};

/** slightly optimized approach */
// first solution
res_idx solution1(const vec& arr) {
	int max_sum = -INF;
	res_idx res{};

	for (size_t i{}; i < arr.size(); i++) {
		int sum = 0;
		for (size_t j{i}; j < arr.size(); j++) {
			sum += arr[j];
			if (sum > max_sum) {
				max_sum = sum;
				res.first = i;
				res.last = j;
			}
		}
	}

	return res;
}

// kadane's algo
res_idx solution2(const vec& arr) {
	res_idx res{};
	size_t s = 0;
	int max_sum = -INF, sum_temp = 0;

	for (size_t i {}; i < arr.size(); i++) {
		sum_temp += arr[i];
		if (sum_temp > max_sum) {
			max_sum = sum_temp;
			res.first = s;
			res.last = i;
		}

		if (sum_temp < 0) {
			sum_temp = 0;
			s = i + 1;
		}
	}

	return res;
}


int main(void) {
	vec arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};

	res_idx res = solution2(arr);
	printf("[%zu, %zu]\n", res.first, res.last);

	return 0;
}
