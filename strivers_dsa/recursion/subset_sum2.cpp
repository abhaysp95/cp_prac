// https://leetcode.com/problems/subsets-ii/

#include <algorithm>
#include <bits/stdc++.h>
#include <ostream>
#include <sstream>

using namespace std;

class Solution {
	public:
		// brute force approach
		vector<vector<int>> subsets_with_dups_bf(vector<int>& nums) {
			vector<vector<int>> res{};  // you can use set here as main container (but I'm using vector cause of return type)
			if (nums.empty()) return res;
			vector<int> temp{};
			temp.reserve(nums.size());

			// sorting is necessary with anything related to uniqueness
			sort(nums.begin(), nums.end(), [](int x, int y) { return x < y; });

			// initiate recursive call
			subsets_bf(0, nums, temp, res);

			return res;
		}

		// optimized approach
		vector<vector<int>> subsets_with_dups(vector<int>& nums) {
			vector<vector<int>> res{};  // you can use set here as main container (but I'm using vector cause of return type)
			if (nums.empty()) return res;
			vector<int> temp{};
			temp.reserve(nums.size());

			// sorting is necessary with anything related to uniqueness
			sort(nums.begin(), nums.end(), [](int x, int y) { return x < y; });

			// initiate recursive call
			subsets(0, nums, temp, res);

			return res;
		}


		ostream& print_arr2d(ostream& out, const vector<vector<int>>& arr2d) {
			out << '[';
			if (!arr2d.empty()) {
				for (const vector<int>& arr: arr2d) {
					this->print_arr(out, arr);
				}
			}
			out << ']';

			return out;
		}

		ostream& print_arr(ostream& out, const vector<int>& arr) {
			out << '[';
			if (!arr.empty()) {
				for (size_t i{}; i < arr.size() - 1; i++) {
					out << arr[i] << ",";
				}
				out << arr[arr.size() - 1];
			}
			out << ']';

			return out;
		}

	private:
		void subsets_bf(size_t idx, const vector<int>& arr, vector<int>& curr_arr, vector<vector<int>>& res) {
			if (arr.size() == idx) {
				// since this is brute force approach
				if (std::find(res.begin(), res.end(), curr_arr) == res.end()) {
					res.emplace_back(curr_arr);
				}
				return;
			}

			curr_arr.push_back(arr[idx]);
			subsets_bf(idx + 1, arr, curr_arr, res);
			curr_arr.pop_back();
			subsets_bf(idx + 1, arr, curr_arr, res);
		}

		void subsets(size_t idx, const vector<int>& arr, vector<int>& cur_arr, vector<vector<int>>& res) {
			res.emplace_back(cur_arr);

			for (size_t i{idx}; i < arr.size(); i++) {
				if (i > idx && arr[i] == arr[i - 1]) continue;
				cur_arr.push_back(arr[i]);
				subsets(i + 1, arr, cur_arr, res);  // call with i, because subsets are 2^n
				cur_arr.pop_back();
			}
		}
};

int main(void) {
	vector<int> arr{};
	string input{};

	cin >> input;
	if (input.size() > 1 && input[0] == '[') {
		input = input.substr(1, input.size() - 1);
	}

	istringstream sstream{input};
	string in{};
	while (std::getline(sstream, in, ',')) {
		arr.emplace_back(stoi(in));
	}

	Solution solution{};
	vector<vector<int>> res = solution.subsets_with_dups(arr);
	solution.print_arr2d(cout, res) << endl;

	return 0;
}
