/* Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.



Constraints:

    1 <= intervals.length <= 105
    intervals[i].length == 2
    -5 * 104 <= starti < endi <= 5 * 104
 */

#include <bits/stdc++.h>

using namespace std;
using vvec = vector<vector<int>>;
using vec = vector<int>;

// if lambda syntax not supported
class Comparator {
	public:
		bool operator()(const vec& p1, const vec& p2) {
			return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
		}
};

class Solution {
	public:
		int eraseOverlapIntervals(vvec& intervals) {
			// sort
			sort(intervals.begin(), intervals.end(), Comparator());

			size_t i = 1, prev = 0, count = 0;
			while (i < intervals.size()) {
				// overlaps
				if (intervals[prev][1] > intervals[i][0]) {
					count++;
					// possibly this previous interval can cover more than one interval or so
					// (try imaging different interval diagrams)
					if (intervals[prev][1] > intervals[i][1]) {
						prev = i;
					}
				} else {
					prev = i;
				}
				i++;
			}

			return count;
		}
};

