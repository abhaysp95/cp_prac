#!/usr/bin/env python3

# https://leetcode.com/problems/product-of-array-except-self/

from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = []
        postfix = []

        mul = 1
        for i, _ in enumerate(nums):
            if i != 0:
                mul *= nums[i - 1]
            prefix.append(mul)

        mul = 1
        nums.reverse()
        for i, _ in enumerate(nums):
            if i != 0:
                mul *= nums[i - 1]
            postfix.append(mul)
        postfix.reverse()

        print(prefix)
        print(postfix)

        output = []
        for i in range(len(nums)):
            output.append(prefix[i] * postfix[i])

        return output
