// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays_brute_force(vector<int>& nums1, vector<int>& nums2) {
        // brute force way
        vector<int> arr(nums1.size() + nums2.size());

        size_t i = 0, j = 0, k = 0;
        while ( i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                arr[k++] = nums1[i++];
            } else {
                arr[k++] = nums2[j++];
            }
        }
        while (i < nums1.size()) {
            arr[k++] = nums1[i++];
        }
        while (j < nums2.size()) {
            arr[k++] = nums2[j++];
        }

        size_t mid = arr.size() / 2;
        return (arr.size() % 2 == 0) ? (arr[mid] + arr[mid - 1]) / (double)2 : arr[mid];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> a, b;
		if (nums1.size() < nums2.size()) {
			a = std::move(nums1);
			b = std::move(nums2);
		} else {
			a = std::move(nums2);
			b = std::move(nums1);
		}

		size_t start = 0, end = a.size();  // smaller one
		size_t tot_sz = a.size() + b.size();

		while (start < end) {
			// mids are inclusive
			size_t mid1 = start + ((end - start) / 2);
			size_t mid2 = (tot_sz / 2) - mid1 - 2;

			int aleft = (mid1 >= 0) ? a[mid1]: INT_MIN;
			int aright = (mid1 + 1 < a.size()) ? a[mid1 + 1] : INT_MAX;
			int bleft = (mid2 >= 0) ? b[mid2]: INT_MIN;
			int bright = (mid2 + 1 < b.size()) ? b[mid2 + 1] : INT_MAX;

			if (aleft <= bright && bleft <= aright) {
				return (a.size() + b.size()) % 2 == 0
					? (max(aleft, bleft) + min(aright, bright)) / (double)2
					: min(aright, bright);
			} else if (aleft > bright) {
				end = mid1;
			} else {
				start = mid1 + 1;
			}
		}

		return 0;
	}
};

/**
 * TODO: do these too
 * https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/description/
 * https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
 */
