// https://leetcode.com/contest/weekly-contest-354/problems/maximum-beauty-of-an-array-after-applying-operation/

#include <bits/stdc++.h>

using namespace std;

class Solution {

	// brute force solution
	int maximumBeauty(vector<int>& nums, int k) {
		vector<pair<int, int>> ranges(nums.size(), pair<int, int>{});

		int minl = INT_MAX, maxr = INT_MIN;
		for (size_t i = 0; i < nums.size(); i++) {
			ranges[i] = make_pair(nums[i] - k, nums[i] + k);
			minl = min(minl, ranges[i].first);
			maxr = max(maxr, ranges[i].second);
		}

		map<int, int> freq{};
		int maxf = 0;
		for (int i = 0; i < nums.size(); i++) {  // this O(N^2) loop will give TLE, because range goes for (10^5 * (2 * 10^5))
			for (int j = minl; j <= maxr; j++) {
				freq[j]++;
				maxf = max(maxf, freq[j]);
			}
		}

		return maxf;
	}
};
