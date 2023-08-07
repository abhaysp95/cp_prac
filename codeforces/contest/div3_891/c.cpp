#include <bits/stdc++.h>
#include <climits>

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
	int subsize = (n * (n - 1)) / 2;

	vector<int> subs(subsize);
	for (int i = 0; i < subs.size(); i++) subs[i] = nxt();
	sort(all(subs));

	vector<int> nums{};
	int i = 0;
	int k = n - 1;
	while (i < subsize) {
		int minn = INT_MAX;
		for (int j = i; j < i + k; j++) {
			minn = min(minn, subs[j]);
		}
		nums.push_back(minn);
		i += k;
		k--;
	}

	nums.push_back(nums[nums.size() - 1]);

	for (const int x: nums) {
		cout << x << " ";
	}
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

