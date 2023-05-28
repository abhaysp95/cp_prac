// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t start = 0, end = matrix.size();
        ssize_t rx = -1;

        while (start < end) {
            size_t mid = (start + end) / 2;
            size_t len = matrix[mid].size();
            if (target >= matrix[mid][0] && target <= matrix[mid][len - 1]) {
                rx = mid;
                break;
            } else if (target < matrix[mid][0]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        if (rx == -1) {
            return false;
        }

        cout << rx << endl;

        start = 0;
        vector<int>& mrow = matrix[rx];
        end = mrow.size();

        while (start < end) {
            size_t mid = (start + end) / 2;

            if (mrow[mid] == target) {
                return true;
            } else if (mrow[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return false;
    }
};

/** NOTE: do these too
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 * https://leetcode.com/problems/split-message-based-on-limit/description/
 */
