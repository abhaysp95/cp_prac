#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	string s;
	cin >> s;

	int maxl = 0, prev = 0, cur = 1;
	for (; cur < sz(s); cur++) {
		if (s[prev] != s[cur]) {
			maxl = max(maxl, cur - prev);
			prev = cur;
		}
	}
	maxl = max(maxl, cur - prev);

	cout << maxl << '\n';

	return 0;
}
