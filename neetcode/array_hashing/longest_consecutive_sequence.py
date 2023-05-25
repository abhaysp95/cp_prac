#!/usr/bin/env python3

from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        max_count = 0

        s = set()
        for x in nums:
            s.add(x)

        for num in nums:
            if (num - 1) not in s:
                count = 0
                while (num + count) in s:
                    count += 1
                max_count = max(max_count, count)

        return max_count
