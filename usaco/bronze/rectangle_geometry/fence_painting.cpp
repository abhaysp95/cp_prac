#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

ifstream fin("paint.in");
ofstream fout("paint.out");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

/* void solve() {
	int a = nxt(fin), b = nxt(fin), c = nxt(fin), d = nxt(fin);
	bool merge = true;
	if (b < c || d < a) merge = false;

	if (!merge) {
		fout << (b - a) + (d - c) << '\n';
	} else {
		fout << max(b, d) - min(a, c) << '\n';
	}
} */

void solve() {
	int a = nxt(fin), b = nxt(fin), c = nxt(fin), d = nxt(fin);
	// total length - length of intersection
	fout << (b - a) + (d - c) - max((min(b, d) - max(a, c)), 0) << '\n';
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

