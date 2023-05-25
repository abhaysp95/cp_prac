// https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return vector<vector<int>>();
	vector<vector<int>> res{};
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size() - 2; i++) {
		if(i > 0 && nums[i] == nums[i - 1]) continue;
		int l{i + 1}, r{static_cast<int>(nums.size() - 1)};
		while (l < r) {
			int sum = nums[i] + nums[l] + nums[r];
			if (0 == sum) {
				res.push_back(vector<int>{nums[i], nums[l], nums[r]}), l++;
				while (nums[l] == nums[l - 1] && l < r) l++;
			}
			else if(0 > sum) l++;
			else r--;
		}
	}
	return res;
    }
};
