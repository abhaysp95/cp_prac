#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt(), p = nxt();
	if (n < m) {
		cout << 0 << '\n';
		return;
	}
	int day = m, i = 1;
	while (day <= n) {
		day = m + (i * p);
		i++;
	}
	cout << (i - 1) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

