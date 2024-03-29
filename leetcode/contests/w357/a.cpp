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

class Solution {
	public:
		string finalString(string& s) {
			string res{};
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == 'i') reverse(res.begin(), res.end());
				else res += s[i];
			}

			return res;
		}
};

void solve() {
	string str{};
	cin >> str;
	Solution solution;
	cout << solution.finalString(str) << '\n';
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
