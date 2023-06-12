#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
	// vector<int> space{};
	public:
		bool wordBreak(string s, vector<string>& wordDict) {
			/* this->space.resize(s.size(), -1);
			return _word_break(s, wordDict, 0); */

			vector<bool> space(s.size() + 1, false);
			space[s.size()] = true;

			for (int i = s.size() - 1; i >= 0; i--) {
				bool status = false;
				for (const string wd: wordDict) {
					if (i + wd.size() <= s.size()) {
						string sub = s.substr(i, wd.size());
						if (sub == wd) {
							status |= space[i + wd.size()];
						}
					}
				}
				space[i] = status;
			}

			return space[0];
		}

		bool _word_break(const string& s, const vector<string>& wordDict, int idx) {
			if (idx == s.size()) {
				return true;
			}

			if (this->space[idx] != -1) {
				return this->space[idx] == 1 ? true : false;
			}

			bool status = false;
			for (const string wd: wordDict) {
				if (idx + wd.size() <= s.size()) {
					string sub = s.substr(idx, wd.size());
					if (wd == sub) {
						status |= _word_break(s, wordDict, idx + wd.size());
					}
				}
			}

			return this->space[idx] = status ? 1 : 0;
		}
};
