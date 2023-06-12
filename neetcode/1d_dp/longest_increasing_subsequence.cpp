#include <bits/stdc++.h>

using namespace std;

class Solution {
	vector<vector<int>> space{};
	public:
		int lengthOfLIS(vector<int>& nums) {
			// memoized
			/* this->space.resize(nums.size(), vector<int>(nums.size() + 1, -1));
			return _max_length(nums, 0, -1); */

			// tabulation
			/* this->space.resize(nums.size() + 1, vector<int>(nums.size() + 1, -1));
			for (int i = nums.size() - 1; i >= 0; i--) {
				for (int prev = i - 1; prev >= -1; prev--) {
					int notake = this->space[i + 1][prev + 1];  // prev can be -1
					int take = 0;
					if (prev == -1 || nums[i] > nums[prev]) {
						take = 1 +this->space[i + 1][i + 1];
					}
					this->space[i][prev + 1] = max(take, notake);
				}
			}

			return this->space[0][0]; */

			// space optimized
			vector<int> cur(nums.size() + 1, 0), next(nums.size() + 1, 0);
			for (int i = nums.size() - 1; i >= 0; i--) {
				for (int prev = i - 1; prev >= -1; prev--) {
					int notake = next[prev + 1];
					int take = 0;
					if (prev == -1 || nums[i] > nums[prev]) {
						take = 1 + next[i + 1];  // here, i is used in place of prev, thus i + 1
					}
					cur[prev + 1] = max(take, notake);
				}
				next = cur;
			}

			return next[0];
		}

		int _max_length(const vector<int>& nums, int idx, int prev) {
			if (idx == nums.size()) {
				return 0;
			}

			if (this->space[idx][prev + 1] != -1) {
				return this->space[idx][prev + 1];
			}

			int notake = _max_length(nums, idx + 1, prev);
			int take = 0;
			if (prev == -1 || nums[idx] > nums[prev]) {  // strictly increasing
				prev = idx;
				take = 1 + _max_length(nums, idx + 1, idx);
			}

			return this->space[idx][prev + 1] = max(notake, take);
		}
};
