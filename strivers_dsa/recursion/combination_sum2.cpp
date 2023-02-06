#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

class Solution {
	public:
		// leet code specific
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			// std::cout << "from vector\n";
			vector<vector<int>> res{};
			vector<int> temp_arr{};
			// sorting needed so that same combination vectors can be compared for uniqueness
			std::sort(candidates.begin(), candidates.end(), [](int& x, int& y) { return x < y; });
			// std::sort(candidates.begin(), candidates.end());
			temp_arr.reserve(candidates.size());
			combi_sum_better(0, target, candidates, temp_arr, res);

			return res;
		}

		set<vector<int>> combinationSum2Set(const vector<int>& candidates, int target) {
			std::cout << "from set\n";
			set<vector<int>> res{};
			vector<int> temp_arr{};
			temp_arr.reserve(candidates.size());
			combi_sum(0, target, candidates, temp_arr, res);

			return res;
		}

		ostream& print_arr2d(ostream& out, const set<vector<int>>& res) {
			if (res.empty()) return out;
			out << '[';
			for (const auto& x: res) {
				out << '[';
				for (size_t i{}; i < x.size() - 1; i++) {
					out << x[i] << ',';
				}
				out << x[x.size() - 1] << ']';
			}
			out << ']';

			return out;
		}

		ostream& print_arr2d(ostream& out, const vector<vector<int>>& res) {
			if (res.empty()) return out;
			out << '[';
			for (const auto& x: res) {
				out << '[';
				for (size_t i{}; i < x.size() - 1; i++) {
					out << x[i] << ',';
				}
				out << x[x.size() - 1] << ']';
			}
			out << ']';

			return out;
		}

		ostream& print_arr(ostream& out, const std::vector<int>& res) {
			if (res.empty()) return out;
			out << '[';
			for (size_t i{}; i < res.size() - 1; i++) {
				out << res[i] << ',';
			}
			out << res[res.size() - 1] << ']';

			return out;
		}
	private:
		void combi_sum(int idx, int target, const vector<int>& arr, vector<int>& to_sum, set<vector<int>>& res) {

			// int sum = accumulate(to_sum.begin(), to_sum.end(), 0);
			if (0 == target) {
				res.emplace(to_sum);
				return;
			} else if (0 > target || arr.size() == idx) {  // (0 > target) only applies if all the elements in arr are + ve
				return;
			}

			to_sum.push_back(arr[idx]);
			combi_sum(idx + 1, target - arr[idx], arr, to_sum, res);
			to_sum.pop_back();
			combi_sum(idx + 1, target, arr, to_sum, res);

		}

		void combi_sum(int idx, int target, const vector<int>& arr, vector<int>& to_sum, vector<vector<int>>& res) {

			// int sum = accumulate(to_sum.begin(), to_sum.end(), 0);
			if (0 == target) {
				// print_arr(std::cout, to_sum);
				if (find(res.begin(), res.end(), to_sum) == res.end()) {
					res.emplace_back(to_sum);
				}
				return;
			} else if (0 > target || arr.size() == idx) {  // (0 > target) only applies if all the elements in arr are + ve
				return;
			}

			to_sum.push_back(arr[idx]);
			combi_sum(idx + 1, target - arr[idx], arr, to_sum, res);
			to_sum.pop_back();
			combi_sum(idx + 1, target, arr, to_sum, res);

		}

		void combi_sum_better(size_t idx, int target, const vector<int>& arr, vector<int>& to_sum, vector<vector<int>>& res) {
			if (0 == target) {
				res.emplace_back(to_sum);
				return;
			} else if ((idx == arr.size()) || (target < arr[idx])) {
				return;
			}
			// the above 'else if ((idx == arr.size()))' is probably not needed because the for loop will end sometime
			for (size_t i{idx}; i < arr.size(); i++) {

				if ((i > idx) && (arr[i] == arr[i - 1])) continue;
				if (target < arr[i]) break;  // this will work because arr is sorted

				to_sum.push_back(arr[i]);
				combi_sum_better(i + 1, target - arr[i], arr, to_sum, res);
				to_sum.pop_back();
			}
		}
};

int main(void) {
	int target{};
	std::string input{};
	std::vector<int> arr{};

	cin >> input;
	cin >> target;

	input = input.substr(1, input.size() - 1);
	std::istringstream istream{input};

	std::string tstr{};
	while (std::getline(istream, tstr, ',')) {
		arr.emplace_back(std::stoi(tstr));
	}

	Solution solution;
	std::vector<std::vector<int>> res = solution.combinationSum2(arr, target);

	solution.print_arr2d(std::cout, res) << std::endl;

	return 0;
}
