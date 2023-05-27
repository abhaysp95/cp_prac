#!/usr/bin/env python3

from typing import List
# from collections import deque

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0] * len(temperatures)

        for i, t in enumerate(temperatures):
            while stack and t > stack[-1][0]:
                _, idx = stack[-1]
                stack.pop()
                res[i] = i - idx
            stack.append([t, i])

        return res
