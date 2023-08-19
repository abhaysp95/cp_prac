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
	int months = nxt();
	vector<int> mdays(months);
	for (int i = 0; i < months; i++) mdays[i] = nxt();

	int td = accumulate(all(mdays), 0);
	int mid = (td + 1) / 2;

	int tsum = 0;
	int mc = 0;
	for (; mc < months; mc++) {
		tsum += mdays[mc];
		if (tsum >= mid) break;
	}
	tsum -= mdays[mc];
	int day = mid - tsum;

	cout << mc + 1 << " " << day << '\n';
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

