#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			vector<vector<int>> res{};

			vector<int> temp{};
			_combination_sum2(candidates, 0, target, target, temp, res);

			return res;
		}

	private:
		void _combination_sum2(const vector<int>& candidates, size_t idx, int target, int ctarget,
				vector<int>& temp, vector<vector<int>>& res) {
			if (target == 0) {
				res.push_back(temp);
				return;
			}
			if (idx == candidates.size()) {
				return;
			}

			for (size_t i = idx; i < candidates.size(); i++) {
				// each number in a combination may only be used once
				if (i > idx && candidates[i] == candidates[i - 1]) continue;
				temp.push_back(candidates[i]);
				_combination_sum2(candidates, idx + 1, target, ctarget - candidates[idx], temp, res);
				temp.pop_back();
			}
		}

		void _combination_sum2_again(const vector<int>& candidates, size_t idx, int target, int ctarget,
				vector<int>& temp, vector<vector<int>>& res) {
			if (target == 0) {
				res.push_back(temp);
				return;
			}
			if (idx == candidates.size()) {
				return;
			}

			// either we take the number or we skip it from the combination
			temp.push_back(candidates[idx]);
			_combination_sum2_again(candidates, idx + 1, target, ctarget - candidates[idx], temp, res);
			temp.pop_back();

			// don't take the number if similar is already taken at all
			if (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
				idx++;
			}
			_combination_sum2_again(candidates, idx + 1, target, ctarget, temp, res);
		}
};

/** TODO: do these too
 * combination sum3
 * count good triplets
 * describe the painting
 * maximum product difference between two pairs
 */
