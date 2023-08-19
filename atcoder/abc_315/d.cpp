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
	int h = nxt(), w = nxt();
	vector<string> grid(h);
	for (int i = 0; i < h; i++) {
		cin >> grid[i];
	}

	vector<vector<pair<int, int>>> rmark{};

	for (int i = 0; i < h; i++) {
		vector<pair<int, int>> mark{};
		int l = 0, r = 1;
		for (int j = 1; j < w; j++) {
			if (grid[i][j - 1] != grid[i][j]) {
				if (r - l >= 2) {
					mark.push_back({l, r});
				}
				l = j;
				r = j;
			}
			r++;
		}
		if (r - l >= 2) mark.push_back({l, r});
		rmark.push_back(mark);
	}

	vector<vector<pair<int, int>>> cmark{};
	for (int i = 0; i < w; i++) {
		vector<pair<int, int>> mark{};
		int l = 0, r = 1;
		for (int j = 1; j < h; j++) {
			if(grid[j][i] == '.') continue;
			if (grid[j - 1][i] != grid[j][i]) {
				if (r - l >= 2) {
					mark.push_back({l, r});
				}
				l = j;
				r = j;
			}
			r++;
		}
		if (r - l >= 2) mark.push_back({l, r});
		cmark.push_back(mark);
	}

	for (int i = 0; i < h; i++) {
		for (pair<int, int>& p: rmark[i]) {
			for (int j = p.first; j < p.second; j++) grid[i][j] = '.';
		}
	}

	for (int i = 0; i < w; i++) {
		for (pair<int, int>& p: cmark[i]) {
			for (int j = p.first; j < p.second; j++) grid[j][i] = '.';
		}
	}

	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] != '.') count++;
		}
	}

	cout << count << '\n';
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

