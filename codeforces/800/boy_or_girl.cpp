#include <bits/stdc++.h>

using namespace std;

int32_t main(void) {
	string str;
	cin >> str;

	map<char, int> freq{};
	for (const char c: str) {
		freq[c]++;
	}

	cout << (freq.size() & 1 ? "IGNORE HIM!" : "CHAT WITH HER!") << '\n';

	return 0;
}
