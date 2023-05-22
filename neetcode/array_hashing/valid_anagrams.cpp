// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> umap{};

        for (const int x: s) {
            umap[x]++;
        }

        for (const int x: t) {
            umap[x]--;
        }

        for (const pair<const int, int>& p: umap) {
            if (p.second != 0) {
                return false;
            }
        }

        return true;
    }
};
