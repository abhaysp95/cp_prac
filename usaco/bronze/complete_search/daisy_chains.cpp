#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
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
	int n = nxt();
	vector<int> parr(n);

	for (int i = 0; i < n; i++) parr[i] = nxt();

	int count = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += parr[j];
			if (sum % (j - i + 1) != 0) continue;
			int avg = sum / (j - i + 1);
			bool match = false;
			for (int k = i; k <= j; k++) {
				if (parr[k] == avg) {
					match = true;
					break;
				}
			}
			if (match) count++;
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
