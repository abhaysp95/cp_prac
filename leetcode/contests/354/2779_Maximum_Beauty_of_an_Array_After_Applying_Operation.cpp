// https://leetcode.com/contest/weekly-contest-354/problems/maximum-beauty-of-an-array-after-applying-operation/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	int offset = 1e5;
	int freq[(int)(3 * 1e5 + 2)];

public:
	Solution() {
		memset(this->freq, 0, sizeof(this->freq));
	}

	// brute force solution
	int maximumBeauty_brute_force(vector<int>& nums, int k) {
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

	int maximumBeauty1(vector<int>& nums, int k) {
		int minl = INT_MAX, maxr = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			minl = min(minl, nums[i] - k);
			maxr = max(maxr, nums[i] + k);

			freq[nums[i] - k + offset]++;
			freq[nums[i] + k + offset + 1]--;
		}

		int maxc = INT_MIN, count = 0;
		for (int i = minl; i <= maxr; i++) {
			count += freq[i + offset];
			maxc = max(maxc, count);
		}

		return count;
	}

	// same approach as above one (but uses map)
	int maximumBeauty2(vector<int>& nums, int k) {
		map<int, int> freq{};
		for (int i = 0; i < nums.size(); i++) {
			freq[nums[i] - k]++;
			freq[nums[i] + k + 1]--;
		}

		int maxc = INT_MIN, count = 0;
		for (const pair<const int, int>& p: freq) {
			count += p.second;
			maxc = max(maxc, count);
		}

		return count;
	}

};

// learnt: carefully observing constraint, as well as, how to show a range in given array and concept of prefix sum
