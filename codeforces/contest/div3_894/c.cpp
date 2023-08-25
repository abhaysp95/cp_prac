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

// brute force (O(n^2)), will give TLE
void solve() {
	int n = nxt();
	vector<int> planks(n);
	for (int i = 0; i < n; i++) planks[i] = nxt();
	vector<int> cplanks = planks;

	int apc = n;
	bool state = true;
	for (int i = 0; i < n; i++) {
		if (apc != planks[i]) {
			state = false;
			break;
		}
		int count = 0;
		for (int j = 0; j < apc; j++) {
			cplanks[j]--;
			if (cplanks[j]) count++;
			else break;
		}
		apc = count;
	}

	cout << (state ? "YES" : "NO") << '\n';
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

