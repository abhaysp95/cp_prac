#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> res{};

		vector<string> temp{};
		_partition(s, 0, temp, res);

		return res;
	}

private:
	void _partition(const string& s, size_t idx, vector<string>& temp, vector<vector<string>>& res) {
		if (idx == s.size()) {
			res.push_back(temp);
			return;
		}

		for (size_t i = idx; i < s.size(); i++) {
			string sb = s.substr(idx, i - idx + 1);
			if (_is_palindrome(sb)) {
				temp.push_back(sb);
				_partition(s, idx + 1, temp, res);
				temp.pop_back();
			}
		}
	}

	bool _is_palindrome(const string& s) {
		size_t sz = s.size();
		for (size_t i = 0; i < sz / 2; i++) {
			if (s[i] != s[sz - i - 1]) {
				return false;
			}
		}

		return true;
	}
};
