#!/usr/bin/env python3

from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs):
        res = defaultdict(list)

        for s in strs:
            counts = [0] * 26
            for c in s:
                counts[ord(c) - ord('a')] += 1
            res[counts].append(s)

        return res.values()
