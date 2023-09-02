#include <bits/stdc++.h>

using namespace std;

// #define DEBUG

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

unordered_map<string, ll> umap{};

ll minimum_cost(const vector<int>& fairs, int idx, int dl, int d, int p) {
	if (idx == sz(fairs)) return 0;

	string key = to_string(idx) + "-" + to_string(dl);
	if (umap.find(key) != umap.end()) return umap[key];

	ll res = LONG_MAX;
	ll l1 = fairs[idx] + minimum_cost(fairs, idx + 1, dl, d, p);
	ll l2 = p + minimum_cost(fairs, idx + 1, dl + d - 1, d, p);
	res = min(l1, l2);
	if (dl != 0) {
		ll l3= minimum_cost(fairs, idx + 1, dl - 1, d, p);
#ifdef DEBUG
		cout << l1 << ", " << l2 << ", " << l3 << '\n';
#endif // DEBUG
		res = min(res, l3);
	}
#ifdef DEBUG
	else cout << l1 << ", " << l2 << '\n';
#endif // DEBUG
	return umap[key] = res;
}

void solve() {
	int n = nxt(), d = nxt(), p = nxt();
	vector<int> fairs(n);
	for (int i = 0; i < n; i++) fairs[i] = nxt();

	cout << minimum_cost(fairs, 0, 0, d, p) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

