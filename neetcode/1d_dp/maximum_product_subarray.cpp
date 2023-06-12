#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int maxProduct(vector<int>& nums) {
			int maxi = INT_MIN;
			int prefix = 1;
			int suffix = 1;

			/** basic idea is:
			 * maintain prefix and suffix for each num and get maximum of them every time
			 * the element can contain negative, but if you keep multiplying from both direction, you will eventually hit maximum
			 * if encounted zero, it can't be included, so either its prefix or suffix will be answer */
			for (size_t i = 0; i < nums.size(); i++) {
				if (prefix == 0) prefix = 1;  // hit zero before, reset
				if (suffix == 0) suffix = 1;
				prefix *= nums[i];
				suffix *= nums[nums.size() - i - 1];
				maxi = max(maxi, max(prefix, suffix));
			}

			return maxi;
		}
};
