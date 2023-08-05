#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

// WA (ACx29, WAx15)
void solve() {
	int n = nxt(), m = nxt();
	vector<int> seller(n, 0);
	vector<int> buyer(m, 0);

	for (int i = 0; i < n; i++) seller[i] = nxt();
	for (int i = 0; i < m; i++) buyer[i] = nxt();

	sort(all(seller));
	sort(all(buyer));

	int res = INT_MAX;
	for (int i = 0; i < n; i++) { // this loop may run 1 to 1e9 at worst
		int sc = upper_bound(all(seller), seller[i]) - seller.begin();
		int bc = sz(buyer) - (lower_bound(all(buyer), seller[i]) - buyer.begin());
		if (sc >= bc) res = min(res, seller[i]);
	}

	cout << res << '\n';
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cerr.tie(nullptr);

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}


