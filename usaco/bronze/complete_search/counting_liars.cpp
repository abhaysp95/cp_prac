#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
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

// TODO: not correct solution, fix it

void solve() {
	int n = nxt();
	vector<pair<char, int>> resp(n);

	for (int i = 0; i < n; i++)
		cin >> resp[i].first, cin >> resp[i].second;

	int min_count = INT_MAX;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (resp[i].first == 'G' && resp[j].first == 'L'
					&& resp[i].second > resp[j].second) count++;
			else if (resp[i].first == 'L' && resp[j].first == 'G'
					&& resp[i].second < resp[j].second) count++;
		}
		min_count = min(min_count, count);
	}

	cout << min_count << '\n';
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

