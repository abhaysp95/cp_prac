#include <bits/stdc++.h>
#include <utility>

using namespace std;

#define sz(a) (int)(a.size())

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

using pp = pair<pair<int, int>, int>;

bool solve() {
	int n = nxt(), k = nxt();
	vector<int> colors(n);
	for (int i = 0; i < n; i++) colors[i] = nxt();

	int ss = 0, se = -1, kc = 0;
	for (int i = 0; i < n; i++) {
		if (colors[i] == colors[ss]) se = i, kc++;
		if (kc == k) break;
	}
	if (kc != k) return false;

	int es = -1, ee = n - 1;
	kc = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (colors[i] == colors[ee]) es = i, kc++;
		if (kc == k) break;
	}
	if (kc != k) return false;

	if (colors[ss] == colors[ee]) return true;

	return se >= es ? false : true;
}

/* bool solve() {
	map<int, pp> record{};
	int n = nxt(), k = nxt();
	int ec = -1;
	for (int i = 0; i < n; i++) {
		int x = nxt();
		if (record.find(x) != record.end()) {
			pp p = record[x];
			if (p.second == k) continue;
			else p.first.second = i + 1, p.second++;
		} else {
			record[x] = {{i + 1, i + 1}, 1};
		}
		if (i + 1 == n) ec = x;
	}

	if (record[ec].second != k) return false;

	for (int i = 0; i < sz(record) - 1; i++) {
		pp p = record[i];
		if (p.first.second < record[ec].first.first) return true;
	}

	return false;
} */

int32_t main(void) {
	int T = nxt();
	while (T--) {
		bool res = solve();
		cout << (res ? "YES" : "NO") << '\n';
	}

	return 0;
}
