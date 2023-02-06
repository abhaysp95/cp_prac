#include <bits/stdc++.h>
#include <numeric>
#include <ostream>
#include <sstream>

std::ostream& print_arr(std::ostream& out, const std::vector<int>& arr) {
	if (arr.empty()) return out;

	out << "[";

	for (size_t i{}; i < arr.size() - 1; i++) {
		out << arr[i] << ",";
	}
	out << arr[arr.size() - 1] << "]";

	return out;
}

std::ostream& print_arrays(std::ostream& out, const std::set<std::vector<int>>& arrays) {
	if (arrays.empty()) return out;

	out << "[";
	for (const std::vector<int>& arr: arrays) {
		print_arr(out, arr);
	}
	out << "]";

	return out;
}

std::ostream& print_arrays(std::ostream& out, const std::vector<std::vector<int>>& arrays) {
	if (arrays.empty()) return out;

	out << "[";
	for (const std::vector<int>& arr: arrays) {
		print_arr(out, arr);
	}
	out << "]";

	return out;
}

void combi_sum(int idx, const std::vector<int>& arr, int res, std::vector<int>& cur_comb) {

	int sum = std::accumulate(cur_comb.begin(), cur_comb.end(), 0);
	if (sum > res) return;  // only applicable if arr contains positive elements
	else if (sum == res) {
		print_arr(std::cout, cur_comb);
		return;
	} else if (arr.size() == idx) {
		/* // print_arr(std::cout, cur_comb);
		if (sum == res) {
			print_arr(std::cout, cur_comb);
			// ans.insert(cur_comb);
		} */
		return;
	}

	cur_comb.push_back(arr[idx]);
	combi_sum(idx, arr, res, cur_comb);
	cur_comb.pop_back();
	combi_sum(idx + 1, arr, res, cur_comb);

	/* cur_comb.push_back(arr[idx]);
	combi_sum(idx, arr, res, cur_comb, ans);
	cur_comb.pop_back();
	if (idx + 1 < arr.size()) {
		cur_comb.push_back(arr[idx + 1]);
		combi_sum(idx + 1, arr, res, cur_comb, ans);
	} */

}

/** for leetcode */
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		std::vector<int> temp_arr{};
		temp_arr.reserve(candidates.size());
		std::vector<std::vector<int>> ans{};
		combi_sum(0, target, candidates, temp_arr, ans);

		return ans;
    }
private:
	void combi_sum(int idx, int target, const std::vector<int>& arr, std::vector<int>& curr_arr, std::vector<std::vector<int>>& ans) {
		int sum = std::accumulate(curr_arr.begin(), curr_arr.end(), 0);
		if (target == sum) {
			ans.emplace_back(curr_arr);
			return;
		} else if (sum > target || idx == arr.size()) {  // first condition only applies if arr have all +ve elements
			return;
		}

		curr_arr.push_back(arr[idx]);
		combi_sum(idx, target, arr, curr_arr, ans);
		curr_arr.pop_back();
		combi_sum(idx + 1, target, arr, curr_arr, ans);
	}
};

int main(void) {

	std::string input{};
	int target{};

	std::cin >> target;
	std::cin >> input;

	input = input.substr(1, input.length() - 1);

	std::istringstream iss(input);
	std::string in{};
	std::vector<int> arr{};

	while (std::getline(iss, in, ',')) {
		arr.push_back(std::stoi(in));
	}

	print_arr(std::cout, arr) << '\n';

	std::vector<int> temp{};
	// std::set<std::vector<int>> ans{};
	// combi_sum(0, arr, target, temp);
	Solution solve{};
	std::vector<std::vector<int>> ans = solve.combinationSum(arr, target);
	print_arrays(std::cout, ans) << "]\n";

	return 0;
}
