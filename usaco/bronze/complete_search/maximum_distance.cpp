#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
	const int N = nxt();
	int xarr[N];
	int yarr[N];

	for (int i = 0; i < N; i++) {
		xarr[i] = nxt();
	}
	for (int i = 0; i < N; i++) {
		yarr[i] = nxt();
	}

	int maxd = INT_MIN;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int x = (xarr[i] - xarr[j]) * (xarr[i] - xarr[j]);
			int y = (yarr[i] - yarr[j]) * (yarr[i] - yarr[j]);
			maxd = max(maxd, x + y);
		}
	}

	cout << maxd << '\n';
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

