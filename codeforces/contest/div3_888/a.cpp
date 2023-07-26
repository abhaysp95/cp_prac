#include <bits/stdc++.h>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt(), k = nxt(), H = nxt();
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		h[i] = nxt();
	}

	int count = 0;
	for (int i = 1; i < m; i++) {  // person
		for (int j = 0; j < n; j++) {
			if (i * k == abs(H - h[j])) {
				count++;
			}
		}
	}

	cout << count << '\n';
}

int32_t main(void) {
	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}
