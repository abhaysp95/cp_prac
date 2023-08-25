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
	int n = nxt();
	vector<int> b(n);
	for (int i = 0; i < n; i++) b[i] = nxt();

	vector<int> a{};
	a.push_back(b[0]);

	for (int i = 1; i < n; i++) {
		if (b[i] < b[i - 1]) {
			a.push_back(1);
		}
		a.push_back(b[i]);
	}

	cout << sz(a) << '\n';
	for (int i = 0; i < sz(a); i++) cout << a[i] << " ";
	cout << '\n';

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

