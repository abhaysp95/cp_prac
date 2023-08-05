#include <bits/stdc++.h>
#include <queue>

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

// TLE
void solve() {
	int n = nxt();
	vector<int> nums(n);
	for (int i = 0; i < n; i++) nums[i] = nxt();

	int count = 0;
	while (true) {
		int minc = INT_MAX, maxc = INT_MIN;
		int mnidx = -1, mxidx = -1;
		for (int i = 0; i < n; i++) {
			if (minc > nums[i]) {
				minc = nums[i], mnidx = i;
			}
			if (maxc < nums[i]) {
				maxc = nums[i], mxidx = i;
			}
		}
		if (maxc - minc == 1 || maxc == minc) break;

		nums[mnidx]++, nums[mxidx]--;
		count++;
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

