#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	string str;
	cin >> str;
	if (str == "ACE"
			|| str == "BDF"
			|| str == "CEG"
			|| str == "DFA"
			|| str == "EGB"
			|| str == "FAC"
			|| str == "GBD") cout << "Yes" << '\n';
	else cout << "No" << '\n';
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

