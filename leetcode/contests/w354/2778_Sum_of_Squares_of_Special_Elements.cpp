// https://leetcode.com/contest/weekly-contest-354/problems/sum-of-squares-of-special-elements/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int sumOfSquares(vector<int>& nums) {
			int sum = 0;
			for (size_t i = 1; i <= nums.size(); i++) {
				if (nums.size() % i == 0)
					sum += (nums[i - 1] * nums[i - 1]);
			}

			return sum;
		}
};
