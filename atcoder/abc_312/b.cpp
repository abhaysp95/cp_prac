#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


inline int nxt() {
	int x;
	cin >> x;
	return x;
}


bool ttregion(const vector<string>& mat, int x, int y) {
	// check top-left
	if (x + 9 > sz(mat) || y + 9 > sz(mat[0])) return false;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i + 1 == 4 || j + 1 == 4) {
				if (mat[i + x][j + y] != '.') return false;
			}
			else if (mat[i + x][j + y] != '#') return false;
		}
	}

	// check bottom right
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 0 || j == 0) {
				if (mat[i + x + 5][j + y + 5] != '.') return false;
			}
			else if (mat[i + x + 5][j + y + 5] != '#') return false;
		}
	}

	return true;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<string> mat(n);
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}

	vector<pair<int, int>> res{};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ttregion(mat, i, j)) {
				res.push_back({i + 1, j + 1});
			}
		}
	}

	sort(res.begin(), res.end(), [&](auto& p1, auto&p2) {
			return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
			});

	for (const auto& p: res) {
		cout << p.first << " " << p.second << '\n';
	}
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

