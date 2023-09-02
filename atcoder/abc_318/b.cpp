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

vector<vector<bool>> grid(100, vector<bool>(100));

void solve() {
	int n = nxt();
	for (int i = 0; i < n; i++) {
		int a = nxt(), b = nxt(), c = nxt(), d = nxt();
		for (int y = c; y < d; y++) {
			for (int x = a; x < b; x++) grid[y][x] = true;
		}
	}

	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			if (grid[i][j]) count++;
	}

	cout << count << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

