#include <bits/stdc++.h>

using namespace std;
using veci = vector<int>;

class Solution {
	public:
		// dp (tabulation) solution
		int rob(veci& nums) {
			if (nums.size() == 1) {
				return nums[0];
			}

			size_t sz = nums.size();
			veci space(sz, 0);
			space[1] = nums[0];

			for (size_t i = 2; i < sz; i++) {
				space[i] = max(nums[i - 1] + space[i - 2], space[i - 1]);
			}
			size_t left = space[sz - 1];

			space.clear();
			space.resize(sz, 0);
			space[1] = nums[1];

			for (size_t i = 2; i < sz; i++) {
				space[i] = max(nums[i] + space[i - 2], space[i - 1]);
			}
			size_t right = space[sz - 1];

			return max(left, right);
		}
};
