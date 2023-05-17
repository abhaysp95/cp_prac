#include <bits/stdc++.h>

using namespace std;

void non_overlapping_substrings(const string& str, size_t idx, vector<string>& substring, set<vector<string>>& substrings) {
	if (idx == str.size()) {
		substrings.emplace(substring);
		return;
	}

	for (size_t i = idx; i < str.size(); i++) {
		substring.push_back(str.substr(idx, i - idx + 1));
		non_overlapping_substrings(str, i + 1, substring, substrings);
		substring.pop_back();
	}
}

int main(void) {
	string str{};
	cin >> str;

	vector<string> substring;
	set<vector<string>> substrings;
	non_overlapping_substrings(str, 0, substring, substrings);

	for (const vector<string>& vs: substrings) {
		for (size_t i = 0; i < vs.size(); i++) {
			cout << vs[i];
			if (i  + 1 < vs.size()) {
				cout << ",";
			}
		}
		cout << '\n';
	}
	cout << endl;

	return 0;
}
