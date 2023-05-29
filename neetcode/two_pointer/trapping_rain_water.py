#!/usr/bin/env python3

# https://leetcode.com/problems/trapping-rain-water/

from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        left = []
        right = []
        water = []

        maxl = height[0]
        for i, x in enumerate(height):
            if i != 0:
                maxl = max(maxl, x)
            left.append(maxl)

        maxr = height[-1]
        height.reverse()
        for i, x in enumerate(height):
            if i!= 0:
                maxr = max(maxr, x)
            right.append(maxr)
        height.reverse()
        right.reverse()

        for i, x in enumerate(height):
            val = min(left[i], right[i]) - height[i]
            if val < 0:
                val = 0
            water.append(val)

        return sum(water)

    def trap_better(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        maxl, maxr = height[l], height[r]

        sum = 0
        while (l < r):
            if maxl <= maxr:
                l += 1
                maxl = max(maxl, height[l])
                sum += maxl - height[l]
            else:
                r -= 1
                maxr = max(maxr, height[r])
                sum += maxr - height[r]

        return sum


# TODO:
# https://leetcode.com/problems/trapping-rain-water-ii/description/
# https://leetcode.com/problems/pour-water/description/
