// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t start = 0, end = nums.size();

        while (start < end) {
            size_t mid = start + (end - start) / 2;
                printf("start: %zu, mid: %zu, end: %zu\n", start, mid, end);
            if (mid != 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else if (mid == 0) {  // rotated array can't reach here
                return nums[mid];
            } else if (nums[mid] <= nums[end - 1]) {  // I'm already on the right (minimum side),
													  // just keep moving more left to get min.
                end = mid;
            } else { // try to move to right-side sorted array
                start = mid + 1;
            }
        }

        return 0;
    }
};

/** TODO: do more of these
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 */
