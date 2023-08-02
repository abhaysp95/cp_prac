#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("pails.in");
ofstream fout("pails.out");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int x = nxt(fin), y = nxt(fin), m = nxt(fin);
	int maxf = INT_MIN;
	int total = 0, i = 0;
	while (i * x <= m) {
		int li = (m - (x * i)) / y;
		// cout << x * i + li * y << '\n';
		maxf = max(maxf, x * i + li * y);
		i++;
	}

	fout << maxf << '\n';

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

