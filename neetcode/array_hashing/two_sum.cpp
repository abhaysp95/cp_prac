// https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vec{};
        for (size_t i = 0; i < nums.size(); i++) {
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first;
        });

        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int sum = vec[start].first + vec[end].first;
            if (sum == target) {
                return vector<int>{vec[start].second, vec[end].second};
            }
            if (sum < target) {
                start++;
            } else {
                end--;
            }
        }

        return vector<int>{};
    }
};
