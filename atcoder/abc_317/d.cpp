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

int selected(const vector<array<int, 3>>& aoki, int idx, int target, vector<vector<int>>& space) {
	if (target <= 0) return 0;
	if (idx == sz(aoki)) return 1e9;

	if (space[idx][target] != -1) return space[idx][target];

	// no take
	int left = selected(aoki, idx + 1, target, space);
	int x = aoki[idx][0];
	int y = aoki[idx][1];
	int z = aoki[idx][2];
	int right = ((x + y + 1) / 2 - x) + selected(aoki, idx + 1, target - z, space);

	return space[idx][target] = min(left, right);
}

void solve() {
	int n = nxt();
	vector<array<int, 3>> takahashi;
	vector<array<int, 3>> aoki;
	for (int i = 0; i < n; i++) {
		int x = nxt(), a = nxt(), z = nxt();
		array<int, 3> arr;
		arr[0] = x, arr[1] = a, arr[2] = z;
		if (x < a) {
			aoki.push_back(arr);
		} else {
			takahashi.push_back(arr);
		}
	}
	int tz = 0, az = 0;
	for (int i = 0; i < sz(takahashi); i++) tz += takahashi[i][2];
	for (int i = 0; i < sz(aoki); i++) az += aoki[i][2];
	if (tz > az) {
		cout << 0 << '\n';
		return;
	}

	// greedy (大きなチャンスがある、Greedyは無理です。)
	/* int count = 0;
	sort(all(aoki), [&](array<int, 3>& a1, array<int, 3>& a2) {
			return a1[2] > a2[2];
			});

	int i = 0;
	while (tz < az) {
		const array<int, 3>& arr = aoki[i];
		int half = (arr[0] + arr[1] + 1) / 2;
		count += (half - arr[0]);
		tz += arr[2];
		az -= arr[2];
	}

	cout << count << '\n'; */

	// DPを試してみましょう
	int target = (tz + az + 1) / 2  - tz;
	vector<vector<int>> space(sz(aoki) + 1, vector<int>(target + 1, -1));
	int res = selected(aoki, 0, target, space);
	cout << (res == 1e9 ? 0 : res) << '\n';
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

