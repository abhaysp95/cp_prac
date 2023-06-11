#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int countSubstrings(string s) {
			size_t count = 0;

			for (size_t i = 0; i < s.size(); i++) {
				// odd
				int l = i, r = i;
				while (l >= 0 && r < s.size() && s[l] == s[r]) {
					l--;
					r++;
					count++;
				}
				l = i, r = i + 1;
				while (l >= 0 && r < s.size() && s[l] == s[r]) {
					count++;
					l--;
					r++;
				}
			}

			return count;
		}
};
