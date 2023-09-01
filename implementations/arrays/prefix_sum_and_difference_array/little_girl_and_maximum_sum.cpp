// https://codeforces.com/contest/276/problem/C

#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), q = nxt();
	vector<int> nums(n);
	for(int i = 0; i < n; i++) nums[i] = nxt();
	vector<int> diff(n + 2);

	for (int i = 0; i < q; i++) {
		int l = nxt(), r = nxt();
		diff[l]++;
		diff[r + 1]--;
	}
	// accumulate
	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}
	sort(all(diff));
	sort(all(nums));

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ((ll)nums[i] * diff[i + 2]);
	}

	cout << sum << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

