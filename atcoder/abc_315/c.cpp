#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define int ll

ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
	map<int, vector<int>> dict{};
	int n = nxt();
	// get max and second max deliciousness
	int maxd = INT_MIN, smaxd = INT_MIN, maxf = 0;
	for (int i = 0; i < n; i++) {
		int f = nxt();
		dict[f].push_back(nxt());
		if (dict[f].at(0) > maxd) {
			smaxd = maxd;
			maxd = dict[f][0];
			maxf = f;
		} else if (dict[f].at(0) > smaxd && dict[f].at(0) < maxd) {
			smaxd = dict[f].at(0);
		}
	}

	for (int i = 0; i < sz(dict); i++) {
		if (sz(dict[i]) > 1) {
			sort(all(dict[i]));
			reverse(all(dict[i]));
		}
	}

	int cmax = maxd + smaxd;
	for (int i = 0; i < sz(dict); i++) {
		if (sz(dict[i]) > 1) {
			cmax = max(cmax, dict[i][0] + (dict[i][1] / 2));
		}
	}

	cout << cmax << '\n';
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

