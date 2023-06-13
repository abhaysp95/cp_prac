/* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.



Constraints:

    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104 */


#include <bits/stdc++.h>

using namespace std;
using vvec = vector<vector<int>>;
using vec = vector<int>;


class Solution {
	public:
		vvec merge(vvec& intervals) {
			// intervals are not sorted (not mentioned in question)

			sort(intervals.begin(), intervals.end(), [](const vec& p1, const vec& p2) {
					return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
					});

			vvec res{};
			size_t i = 1;
			while (i < intervals.size()) {
				if (intervals[i - 1][1] < intervals[i][0]) {
					res.push_back(intervals[i - 1]);
				} else {
					intervals[i][0] = max(intervals[i - 1][0], intervals[i][0]);
					intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
				}
			}
			res.push_back(intervals[intervals.size() - 1]);

			return res;
		}

};
