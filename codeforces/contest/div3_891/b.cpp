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

inline ll nxt(istream& cin = std::cin) {
	ll x;
	cin >> x;
	return x;
}

string max_num(const string& a, const string& b) {
	return a.size() == b.size() ? max(a, b) : a.size() > b.size() ? a : b;
}

void solve() {
	string num;
	cin >> num;
	int n = sz(num);

	string maxn = num;
	int carry = 0;
	for (int k = n - 2; k >= 0; k--) {
		maxn = max_num(maxn, num);
		if (num[k + 1] - '0' >= 5) {
			if (num[k] - '0' == 9) {  // it's 9 and should be increased by 1
				num[k + 1] = '0';
				// num[k] = '0', k--;
				while (k >= 0 && num[k] - '0' == 9) {
					num[k] = '0';
					k--;
				}
				if (k == -1) {
					num = '1' + num;
					break;
				} else num[k]++;
			} else {
				num[k]++;
			}
		}
		num[k + 1] = '0';
	}
	maxn = max_num(maxn, num);
	if (num[0] - '0' >= 5) {
		num[0] = '0';
		num = '1' + num;
	}
	maxn = max_num(maxn, num);

	cout << maxn << '\n';
}

/* void solve() {
	string num;
	cin >> num;
	int ns = sz(num);

	if (num[0] - '0' < 5) {
		int i = 0;
	} else {
		num = '1' + string(ns, '0');
	}

	cout << num << '\n';
} */

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
