#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			vector<vector<int>> res{};
			vector<int> temp{};
			temp.reserve(candidates.size());

			_combination_sum(candidates, 0, target, target, temp, res);

			return res;
		}

	private:
		void _combination_sum(const vector<int>& candidates, int idx, int target, int ctarget, vector<int>& temp, vector<vector<int>>& res) {
			if (target == 0) {
				res.push_back(temp);
				return;
			}
			if (target < 0 || idx == candidates.size()) {
				return;
			}

			temp.push_back(candidates[idx]);
			// same number chosen unlimited number of time
			_combination_sum(candidates, idx, target, target - candidates[idx], temp, res);
			temp.pop_back();
			_combination_sum(candidates, idx + 1, target, target, temp, res);
		}
};
