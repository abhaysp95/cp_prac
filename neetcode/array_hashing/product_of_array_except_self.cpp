// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0), suffix(nums.size(), 0);

        int mul = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i != 0) {
                mul *= nums[i - 1];
            }
            prefix[i] = mul;
        }

        mul = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i != nums.size() - 1) {
                mul *= nums[i + 1];
            }
            suffix[i] = mul;
        }

        vector<int> res(nums.size(), 0);
        for (size_t i = 0; i < nums.size(); i++) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
