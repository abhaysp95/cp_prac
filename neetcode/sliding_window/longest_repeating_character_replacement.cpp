// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// brute force approach
    int characterReplacement(string s, int k) {
        size_t maxc = 0;
        for (size_t i = 0; i < s.size(); i ++) {
            for (size_t j = i + 1; j <= s.size(); j++) {
                unordered_map<char, size_t> umap{};
                for (size_t k = i; k < j; k++) {
                    umap[s[k]]++;
                }
                // get max
                size_t max_sub_count = 0;
                for (const pair<char, size_t>& p: umap) {
                    max_sub_count = max(max_sub_count, p.second);
                }
                if ((j - i) - max_sub_count <= k) {
                    maxc = max(maxc, (j - i));
                }
            }
        }

        return maxc;
    }
};
