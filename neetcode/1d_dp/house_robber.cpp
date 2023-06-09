#include <bits/stdc++.h>

using namespace std;
using veci = vector<int>;

class Solution {
	veci space{};
	public:
		int rob(veci& nums) {
			/* this->space.resize(nums.size(), -1);
			return rob_house_pick_nopick_memoized(nums, 0); */
			// return rob_house_memoized(nums, 0);

			// tabulation
			this->space.resize(nums.size() + 1, 0);
			this->space[1] = nums[0];

			for (size_t i = 2; i <= nums.size(); i++) {
				this->space[i] = max(
						nums[i - 1] + this->space[i - 2],  // take
						this->space[i - 1]  // no take
						);
			}

			return this->space[nums.size()];
		}

		// btw, this is also correct solution
		int rob_house_memoized(const veci& nums, size_t idx) {
			if (idx >= nums.size()) {
				return 0;
			}

			if (this->space[idx] != -1) {
				return this->space[idx];
			}

			int maxc = 0;
			for (size_t i = idx; i < nums.size(); i++) {
				// can't rob adjacent house
				maxc = max(maxc, nums[i] + rob_house_memoized(nums, i + 2));
			}

			return this->space[idx ] = maxc;
		}

		int rob_house_pick_nopick_memoized(const veci& nums, size_t idx) {
			if (idx >= nums.size()) {
				return 0;
			}

			if (this->space[idx] != -1) {
				return this->space[idx];
			}

			return this->space[idx] = max(nums[idx] + rob_house_pick_nopick_memoized(nums, idx + 2),
					rob_house_pick_nopick_memoized(nums, idx + 1));
		}

};
