// https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		// an intuition of brute force approach (it's buggy though)
		/* string minWindow(string s, string t) {
			unordered_map<char, size_t> have{}, need{};

			for (size_t i = 0; i < t.size(); i++) {
				have[t[i]]++;
			}

			size_t l = 0, r = 0, pl = 0;

			size_t minw = INT_MAX;
			while (l + r < s.size()) {
				r = l;
				while (r < s.size()) {
					need[s[r]]++;
					if (have.find(s[r]) != have.end()) {
						// check if condition matches
						bool matched = true;
						for (const pair<char, size_t>& phave: have) {
							if (need.find(phave.first) == need.end()) {
								matched = false;
								break;
							}
						}
						if (matched) {
							pl = l;
							minw = min(minw, (r - l + 1));
							break;
						}
					}
					r++;
				}
				need.clear();
				size_t pl = l;
				while (have.find(s[++l]) == have.end()) {}
			}

			if (minw == INT_MAX) return "";
			return s.substr(pl, minw);
		} */

		string minWindow(string s, string t) {
			// have is what we have (from t), need is what we need (from s)
			unordered_map<char, size_t> have{}, need{};
			size_t havec = 0, needc = 0;  // these are count

			for (size_t i = 0; i < t.size(); i++) {
				have[t[i]]++;
			}
			havec = have.size();

			size_t idx = 0, minw = s.size() + 1;  // idx is from where will this minimum window start

			size_t l = 0, r = 0;
			while (r < s.size()) {
				need[s[r]]++;

				if (have.find(s[r]) != have.end() && need[s[r]] == have[s[r]]) {
					needc++;
				}

				// move window to the right
				while (havec == needc) {
					if (minw > (r - l + 1)) {
						idx = l;
						minw = (r - l + 1);
					}
					need[s[l]]--;

					if (have.find(s[l]) != have.end() && need[s[l]] < have[s[l]]) {
						needc--;
					}
					l++;
				}
				r++;
			}

			if (minw > s.size() || (idx + minw) > s.size()) return "";
			return s.substr(idx, minw);
		}
};


/** TODO: do these too
 * https://leetcode.com/problems/minimum-window-subsequence/
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 * https://leetcode.com/problems/sliding-window-maximum/description/
 */
