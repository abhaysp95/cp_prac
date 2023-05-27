# https://leetcode.com/problems/car-fleet/

from typing import List

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        sz = len(speed)

        if sz <= 1:
            return sz

        stack = []
        right_order = [[p, s] for p, s in zip(position, speed)]

        right_order.sort()  # sorts based on first element of tuple
        stack.append(right_order[-1])

        for p, s in right_order[-2::-1]:
            ahead = (target - stack[-1][0]) / stack[-1][1]
            behind = (target - p) / s

            # if car behind is taking more time than car ahead to reach target,
            # it'll never collide, thus no fleet here
            if (behind > ahead):
                stack.append([p, s])

        return len(stack)
