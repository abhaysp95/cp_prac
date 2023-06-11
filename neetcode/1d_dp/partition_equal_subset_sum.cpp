#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution {
	public:
		bool canPartition(vector<int>& nums) {
			int sum = accumulate(nums.begin(), nums.end(), 0);
			if (sum % 2 != 0) return false;

			_partition(nums, sum / 2, nums.size() - 1);
		}

		bool _partition(const vector<int>& nums, int target, int idx) {
			if (target == 0) {
				return true;
			}
			if (idx < 0 || target < 0) {
				return false;
			}

			return _partition(nums, target - nums[idx], idx - 1)
				|| _partition(nums, target, idx - 1);
		}
};
