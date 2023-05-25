// https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
       size_t i{}, j{height.size() - 1};
       size_t max_area{0};

       while (i < j) {
           size_t cur_area = min(height[i], height[j]) * (j - i);
           max_area = max(max_area, cur_area);

           if (height[i] < height[j]) {
               i++;
           } else {
               j--;
           }
       }

       return max_area;
    }
};
