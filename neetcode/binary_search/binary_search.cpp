#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int search(const vector<int>& nums, int target) {
			size_t start = 0, end = nums.size();

			while (start < end) {
				size_t mid = (start + end) / 2;
				if (nums[mid] == target) return mid;
				else if (nums[mid] < target) start = mid + 1;
				else end = mid;
			}

			return -1;
		}
};

/** NOTE:
 * https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/description/
 */
