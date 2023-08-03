#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("gymnastics.in");
ofstream fout("gymnastics.out");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
	const int k = nxt(fin), n = nxt(fin);
	vector<vector<int>> data(k, vector<int>(n));

	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++) data[i][j] = nxt(fin);

	// vector<vector<vector<bool>>> for each cow, have each session data (session data is 2d)
	// make session data by traversing for each cow in 2d data
	// merge each cows final session data and the place in final array with true, will make pair with cow

	vector<vector<vector<bool>>> fsdata{};

	for (int c = 0; c < n; c++) {
		vector<vector<bool>> sdata{};
		for (int i = 0; i < k; i++) {
			vector<bool> tsdata(n, false);
			bool found = false;
			for (int j = 0; j < n; j++) {
				if (data[i][j] == c + 1) found = true;
				if (found) {
					tsdata[data[i][j] - 1] = true;
				}
			}
			sdata.push_back(tsdata);
		}
		fsdata.push_back(sdata);
	}

	vector<pair<int, int>> pairs{};

	for (int c = 0; c < n; c++) {
		vector<bool> fdata(n, true);
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				fdata[j] = fdata[j] && fsdata[c][i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			if (fdata[i] && c != i) {
				pairs.push_back({c + 1, i + 1});
				cout << "(" << c + 1 << ", " << i + 1 << ")" << '\n';
			}
		}
	}

	fout << pairs.size() << '\n';
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

