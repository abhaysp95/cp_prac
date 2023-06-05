#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> res{};
			if (nums.empty()) return res;

			vector<int> temp{};
			_subsets(nums, 0, temp, res);

			return res;
		}

	private:
		void _subsets(const vector<int>& nums, size_t idx, vector<int>& temp, vector<vector<int>>& res) {
			if (idx == nums.size()) {
				res.push_back(temp);
				return;
			}

			_subsets(nums, idx + 1, temp, res);
			temp.push_back(nums[idx]);
			_subsets(nums, idx + 1, temp, res);
			temp.pop_back();
		}
};
