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

bool checkmat(const vector<string>& carpet, int n, int m) {
	string name = "vika";
	int i = 0, j = 0;

	for (int k = 0; k < n; k++) {
		while (i < m && j < 4) {
			if (carpet[k][i] == name[j]) j++;
			i++;
		}
		if (j != 4) return false;
	}

	return true;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<string> carpet(n);
	for (int i = 0; i < n; i++) {
		cin >> carpet[i];
	}

	/* if (checkmat(carpet, n, m)) {
		cout << "YES\n";
	} else {
		vector<string> carpet2(m, string(n, '\0'));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				carpet2[j][i] = carpet[i][j];
			}
		}
		if (checkmat(carpet2, m, n)) {
			cout << "YES\n";
		} else cout << "NO\n";
	} */

	string name = "vika";
	int fnd = 0;
	for (int i = 0; i < m; i++) {
		bool found = false;
		for (int j = 0; j < n; j++) {
			if (carpet[j][i] == name[fnd]) {
				found = true;
			}
		}
		if (found) fnd++;
	}
	if (fnd == 4) cout << "YES\n";
	else cout << "NO\n";
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cerr.tie(nullptr);

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

