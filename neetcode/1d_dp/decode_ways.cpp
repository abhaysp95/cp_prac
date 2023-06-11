#include <bits/stdc++.h>

using namespace std;

class Solution {
	vector<int> space{};
	public:
		int numDecodings(string s) {
			/* this->space.resize(s.size(), -1);
			return _decode(s, s.size() - 1); */

			// tabulation solution
			this->space.resize(s.size() + 1, 0);
			this->space[s.size()] = 1;
			this->space[s.size() - 1] = s[s.size() - 1] == '0' ? 0 : 1;

			for (int i = s.size() - 2; i >= 0; i--) {
				if (s[i] == '0') {
					this->space[i] = 0;
				} else {
					this->space[i] = this->space[i + 1] + this->space[i + 2];
				}
			}

			return this->space[0];
		}

		int _decode(const string& s, int idx) {
			if (idx < 0) {
				return 1;
			}

			if (this->space[idx] != -1) {
				return this->space[idx];
			}

			int res = 0;
			if (s[idx] != '0') {
				res += _decode(s, idx - 1);
			}
			if (idx > 0 && s[idx - 1] != '0') {
				string num = s.substr(idx - 1, 2);
				if (stoi(num) <= 26) {
					res += _decode(s, idx - 2);
				}
			}

			return this->space[idx] = res;
		}
};
