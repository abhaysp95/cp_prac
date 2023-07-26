#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(a) (int)(a.size())

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	int n = nxt();
	int sx = 0, sy = 0, sz = 0;
	while (n--) {
		sx += nxt(), sy += nxt(), sz += nxt();
	}
	if (sx == 0 && sy == 0 && sz == 0) {
		cout << "YES" << '\n';
	} else cout << "NO" << '\n';

	return 0;
}
