#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

vector<vector<int>> weights(17, vector<int>(17, 0));

int min_weight(int idx, int n, vector<bool>& space) {
	int res = 0;

	if (space[idx]) return 0;

	space[idx] = true;
	for (int i = idx; i <= n; i++) {
		if (!space[i]) {
			space[i] = true;
			res = max(res, weights[idx][i] + min_weight(idx + 1, n, space));
			space[i] = false;
		}
	}
	space[idx] = false;

	return res;
}

void solve() {
	int n = nxt();
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			weights[i][j] = nxt();
		}
	}
	vector<bool> space(17, false);

	cout << min_weight(1, n, space) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

