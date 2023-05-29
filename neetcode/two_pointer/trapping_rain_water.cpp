// https://leetcode.com/problems/trapping-rain-water/


#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int trap(vector<int>& height) {
			int sum = 0;

			int l = 0, r = height.size() - 1;
			int maxl = height[l], maxr = height[r];

			while (l < r) {
				if (maxl <= maxr) {
					l++;
					maxl = max(maxl, height[l]);
					sum += (maxl - height[l]);
				} else {
					r++;
					maxr = max(maxr, height[r]);
					sum += (maxr - height[r]);
				}
			}

			return sum;
		}
};

/** TODO:
* https://leetcode.com/problems/trapping-rain-water-ii/description/
* https://leetcode.com/problems/pour-water/description/
*/
