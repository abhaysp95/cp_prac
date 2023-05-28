// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /* int largestRectangleArea(vector<int>& heights) {
        size_t sz = heights.size() - 1;
        size_t l = 0, r = sz - 1;
        size_t maxl = heights[l], maxr = heights[r];
        size_t maxlh = heights[l], maxrh = heights[r];
        size_t maxa = max(maxl, maxr);
        size_t minl = heights[l], minr = heights[r];

        while (l < r) {
            if (maxl < maxr) {
                l++;
                minl = min(minl, (size_t)heights[l]);
                maxlh = max(maxlh, minl * (l + 1));
                maxl = max(maxl, max(maxlh, (size_t)heights[l]));
                maxa = max(maxa, maxl);
            } else {
                r--;
                minr = min(minr, (size_t)heights[r]);
                maxrh = max(maxrh, minr * (sz - r));
                maxr = max(maxr, max(maxrh, (size_t)heights[r]));
                maxa = max(maxa, maxr);
            }
        }

        return maxa;
    } */

    int largestRectangleArea(vector<int>& heights) {
        stack<pair<size_t, size_t>> st{};

        size_t sz = heights.size();
        if (sz == 1) return heights[0];

        st.push({0, heights[0]});  // {idx, heights[idx]}
        size_t maxa = heights[0];

        for (size_t i = 1; i < heights.size(); i++) {
            size_t j = i;
            while (!st.empty() && heights[i] < st.top().second) {
                maxa = max(maxa, (i - st.top().first) * st.top().second);
				j = st.top().first;
                st.pop();
            }
            st.push({j, heights[i]});
        }

        while (!st.empty()) {
            maxa = max(maxa, (sz - st.top().first) * st.top().second);
            st.pop();
        }

        return maxa;
    }
};

/** TODO: do these too
 * https://leetcode.com/problems/maximal-rectangle/description/
 * https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/
 */
