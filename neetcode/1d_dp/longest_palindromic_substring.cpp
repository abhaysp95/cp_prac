#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) {
			size_t i = 0;
			string maxs = "";

			while (i < s.size()) {
				// odd
				int l = i, r = i;
				while (l >= 0 && r < s.size() && s[l] == s[r]) {
					if (maxs.size() < (r - l + 1)) maxs = s.substr(l, (r - l + 1));
					l--;
					r++;
				}
				// even
				l = i, r = i + 1;
				while (l >= 0 && r < s.size() && s[l] == s[r]) {
					if (maxs.size() < (r - l + 1)) maxs = s.substr(l, (r - l + 1));
					l--;
					r++;
				}
			}

			return maxs;
		}
};

/** TODO: do these too
 * longest palindromic subsequence
 * short palindrome
 * palindrome permutation
 * plaindrome pairs
 */
