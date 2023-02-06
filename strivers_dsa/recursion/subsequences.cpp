// it can be non-contiguous as well

#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>

void print_arr(const std::vector<int>& arr) {
	std::cout << "[";
	for (size_t i{}; i < arr.size() - 1; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[arr.size() - 1] << "]" << std::endl;
}

void subsequences(size_t start, size_t end, const std::vector<int> &arr, std::set<std::vector<int>>& res) {

	if (arr.size() >= end) {
		return;
	}

	std::vector<int> current(end - start + 1);
	for (size_t i{0}; i < (end - start + 1); i++) {
		current[i] = arr[start + i];
		// std::cout << arr[start + i] << " ";
	}
	// std::cout << '\n';
	if (res.find(current) == res.end()) {
		res.insert(current);
	}

	subsequences(start, end + 1, arr, res);
	subsequences(start + 1, end + 1, arr, res);

}

void subsequences2(size_t idx, const std::vector<int>& arr, std::vector<int> res) {

	if (idx >= arr.size()) {
		if (!res.empty())
			print_arr(res);
		return;
	}

	// when I take it
	res.push_back(arr[idx]);
	subsequences2(idx + 1, arr, res);
	res.pop_back();
	subsequences2(idx + 1, arr, res);

}


int main(void) {

	std::vector<int> input{};
	// int x{};
	std::string str{};

	/* while (std::cin >> x) {
		// input.push_back(std::stoi(str));
		input.push_back(x);
	} */
	while (std::getline(std::cin, str, ',')) {
		input.push_back(std::stoi(str));
	}

	std::set<std::vector<int>> res{};

	/* subsequences(0, 0, input, res);

	for (const std::vector<int>& vec: res) {
		for (int x: vec) {
			std::cout << x << " ";
		}
		std::cout << '\n';
	} */

	subsequences2(0, input, std::vector<int>{});
}
