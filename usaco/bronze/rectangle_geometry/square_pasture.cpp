#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("square.in");
ofstream fout("square.out");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int ax1 = nxt(fin), ay1 = nxt(fin), ax2 = nxt(fin), ay2 = nxt(fin);
	int bx1 = nxt(fin), by1 = nxt(fin), bx2 = nxt(fin), by2 = nxt(fin);

	int arm = max((max(ax2, bx2) - min(ax1, bx1)),
			(max(ay2, by2) - min(ay1, by1)));

	fout << arm * arm << '\n';
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

