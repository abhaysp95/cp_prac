#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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
	int n = nxt(), m = nxt();
	vector<pair<int, int>> info(m);
	for (int i = 0; i < m; i++) {
		info[i].first = nxt(), info[i].second = nxt();
	}

	set<int> cndts{};
	for (int i = 0; i < m; i++) {
		cndts.insert(info[i].first);
	}
	for (int i = 0; i < m; i++) {
		if (cndts.find(info[i].second) != cndts.end()) {
			cndts.erase(info[i].second);
		}
	}

	if (cndts.size() == 1) {
		cout << *cndts.begin() << '\n';
	} else cout << -1 << '\n';
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

