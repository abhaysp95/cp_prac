#include <iostream>
#include <string>
#include <vector>
#include <numeric>

void print_arr(const std::vector<int>& arr) {
	if (arr.empty()) return;

	std::cout << "[";
	for (size_t i{}; i < arr.size() - 1; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[arr.size() - 1] << "]" << std::endl;
}

void subsequences_sum(size_t idx, int res, const std::vector<int>& arr, std::vector<int>& to_sum) {

	if (arr.size() <= idx) {

		int sum = std::accumulate(to_sum.begin(), to_sum.end(), 0);
		if (sum == res) {
			// std::cout << "summed: \n";
			print_arr(to_sum);
		}
		return;
	}

	to_sum.push_back(arr[idx]);
	subsequences_sum(idx + 1, res, arr, to_sum);
	to_sum.pop_back();
	subsequences_sum(idx + 1, res, arr, to_sum);
}

bool single_subsequence_sum(size_t idx, int res, const std::vector<int>& arr, std::vector<int>& to_sum) {

	if (arr.size() == idx) {
		// print_arr(to_sum);
		if (std::accumulate(to_sum.begin(), to_sum.end(), 0) == res) {
			// std::cout << "sum: \n";
			print_arr(to_sum);
			return true;
		}
		return false;
	}

	to_sum.push_back(arr[idx]);
	if (single_subsequence_sum(idx + 1, res, arr, to_sum) == true) {
		return true;
	}
	to_sum.pop_back();
	if (single_subsequence_sum(idx + 1, res, arr, to_sum) == true) {
		return true;
	}

	return false;
}

size_t count_subsequences_with_sum(size_t idx, int sum, const std::vector<int>& arr, int res) {
	if (arr.size() == idx) {
		if (res == sum) {
			return 1;
		}

		return 0;
	}

	size_t temp_sum{};
	temp_sum += count_subsequences_with_sum(idx + 1, sum, arr, res + arr[idx]);
	temp_sum += count_subsequences_with_sum(idx + 1, sum, arr, res);

	return temp_sum;
}

// one more base case can be there, if (cur_sum > res) return 0; but this will only work if arr has +ve elements

int main(void) {

	std::vector<int> input{};
	std::string in{};

	int res{};
	std::cin >> res;

	while (std::getline(std::cin, in, ',')) {
		input.push_back(std::stoi(in));
	}

	// std::cout << "this\n";

	std::vector<int> temp{};
	subsequences_sum(0, res, input, temp);
	// single_subsequence_sum(0, res, input, temp);
	std::cout << count_subsequences_with_sum(0, res, input, 0) << std::endl;

	return 0;
}
