#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> res{};
			_permute(nums, 0, res);

			return res;
		}

	private:
		void _permute(vector<int>& nums, size_t idx, vector<vector<int>>& res) {
			for (size_t i = idx; i < nums.size(); i++) {
				swap(nums[i], nums[idx]);
				_permute(nums, idx + 1, res);
				swap(nums[i], nums[idx]);
			}

			if (idx == nums.size()) {
				res.push_back(nums);
			}
		}
};
