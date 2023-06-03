// https://leetcode.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq{};
		vector<int> res{};
		res.reserve(nums.size() - k + 1);

		size_t l = 0, r = 0;
		while (r < nums.size()) {
			while (!dq.empty() && dq.back() < nums[r]) {
				dq.pop_back();
			}
			dq.push_back(nums[r]);
			/* if (r - l + 1 < k) {
				r++;
			} */
			if (r - l + 1 == k) {  // length is now equal to window, start sliding the window
				res.push_back(dq.front());
				if (dq.front() == nums[l]) {
					dq.pop_front();
				}
				l++;
			}
			r++;
		}

		return res;
	}
};

/** TODO: do these too
 * https://leetcode.com/problems/sliding-window-median/
 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/
 * https://leetcode.com/problems/paint-house-ii/description/
 * https://leetcode.com/problems/jump-game-vi/description/
 */
