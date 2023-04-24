// https://leetcode.com/problems/subsets/

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> res{};

			// condition: only print unique subsets
			sort(nums.begin(), nums.end());

			vector<int> temp{};
			get_subsets(nums, 0, temp, res);

			return res;
		}

		ostream& print_matrix(ostream& out, vector<vector<int>>& matrix) {
			if (matrix.size() == 0) return out;

			/* for (size_t i{}; i < matrix.size() - 1; i++) {
				for (size_t j{}; j < matrix[i].size() - 1; j++) {
					cout << matrix[i][j] << ", ";
				}
				cout << matrix[i][matrix[i].size() - 1] << '\n';
			}
			for (size_t j{}; j < matrix[matrix.size() - 1].size() - 1; j++) {
				cout << matrix[matrix.size() - 1][j] << ", ";
			}
			cout << matrix[matrix.size() - 1][matrix[matrix.size() - 1].size() - 1] << '\n'; */

			for (vector<int>& arr: matrix) {
				for (int x: arr) {
					cout << x << " ";
				}
				cout << '\n';
			}

			return out;
		}

	private:
		void get_subsets(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& res) {
			// base condition
			if (idx == nums.size()) {
				res.push_back(temp);
				return;
			}

			/* for (int i = idx; i < nums.size(); i++) {
				if (i > idx && nums[i] == nums[i - 1]) continue;
				temp.push_back(nums[i]);
				get_subsets(nums, idx + 1, temp, res);
				temp.pop_back();
			} */

			if (idx > 0 && nums[idx] == nums[idx -1]) {
				get_subsets(nums, idx + 1, temp, res);
			} else {
				get_subsets(nums, idx + 1, temp, res);
				temp.push_back(nums[idx]);
				get_subsets(nums, idx + 1, temp, res);
				temp.pop_back();
			}
		}
};

int main(void) {
	vector<int> nums = {1, 1, 2, 3};

	Solution sol{};
	vector<vector<int>> res = sol.subsets(nums);
	sol.print_matrix(cout, res);

	return 0;
}
