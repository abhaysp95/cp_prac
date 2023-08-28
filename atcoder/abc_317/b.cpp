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
	vector<int> nums(n);
	for (int i = 0; i < n; i++) nums[i] = nxt();

	sort(all(nums));
	int tsum = ((n + 1) * (2 * nums[0] + n)) / 2;
	int asum = accumulate(all(nums), 0);

	if (tsum != asum)
		cout << tsum - asum << '\n';
	else {
		if (nums[0] != 1) cout << nums[0] - 1 << '\n';
		else cout << nums[0] + 1 << '\n';
	}
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

