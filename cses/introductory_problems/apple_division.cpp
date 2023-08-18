#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define int ll


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

int min_diff(vector<int>& arr, int idx, int fsum, int ssum) {
	if (idx == sz(arr)) {
		return abs(fsum - ssum);
	}

	// what's wrong with this ? (some test cases were failing)
	/* return min(min_diff(arr, idx + 1, fsum + arr[idx], ssum - arr[idx]),
			min_diff(arr, idx + 1, fsum, ssum)); */
	return min(min_diff(arr, idx + 1, fsum + arr[idx], ssum),
			min_diff(arr, idx + 1, fsum, ssum + arr[idx]));
}

void solve() {
	int n = nxt();
	vector<int> arr(n);
	for (int i = 0; i < n; i++) arr[i] = nxt();

	// int sum = accumulate(all(arr), 0);
	int res = min_diff(arr, 0, 0, 0);

	cout << res << '\n';
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

