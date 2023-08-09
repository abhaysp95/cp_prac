// https://leetcode.com/contest/weekly-contest-354/problems/length-of-the-longest-valid-substring/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int longestValidSubstring(string word, vector<string>& forbidden) {
			unordered_set<string> fbd{};
			for (const string& s: forbidden) {
				fbd.insert(s);
			}

			int curright = word.size() - 1, maxc = 0;
			for (int left = word.size() - 1; left >= 0; left--) {
				// <= because, curright is inclusive and since <=, thus left + 9, instead of left + 10
				for (int right = left; right <= min(left + 9, curright); right++) {
					string sub = word.substr(left, right - left + 1);
					if (fbd.find(sub) != fbd.end()) {
						curright = right - 1;
					}
				}

				maxc = max(maxc, curright - left + 1);
			}

			return maxc;
		}
};

// learnt: carefully observe constraint, this solution works because, forbidden[i].size() <= 10 and thus maximum this loop will run is 1e6 (times), so no TLE
