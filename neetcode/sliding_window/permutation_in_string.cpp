// https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// brute force
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());

        for (size_t i = 0; i < s2.size(); i++) {
            for (size_t j = i + 1; j <= s2.size(); j++) {  // j is exclusive
                string t = s2.substr(i, (j - i));
                sort(t.begin(), t.end());
                if (s1 == t) {
                    return true;
                }
            }
        }

        return false;
    }
};
