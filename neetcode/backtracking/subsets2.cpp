#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int>> res{};
			sort(nums.begin(), nums.end());

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

			// since there can be duplicate and we need unique subsets, we already have sorted the array
			// we take it
			temp.push_back(nums[idx]);
			_subsets(nums, idx + 1, temp, res);
			temp.pop_back();

			// we skip all duplicates
			while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
				idx += 1;
			}
			_subsets(nums, idx + 1, temp, res);
		}

		void _subsets_again(const vector<int>& nums, size_t idx, vector<int>& temp, vector<vector<int>>& res) {
			res.push_back(temp);

			for (size_t i = idx; i < nums.size(); i++) {
				// if the two numbers are same (in continuity) and you're not picking it up for the first time
				if (i > idx && nums[i] == nums[i - 1]) continue;
				temp.push_back(nums[i]);
				_subsets_again(nums, i + 1, temp, res);
				temp.pop_back();
			}
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/word-subsets/
 * https://leetcode.com/problems/find-array-given-subset-sums/description/
 */
