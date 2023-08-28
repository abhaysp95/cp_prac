#include <algorithm>
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

int traverse(const vector<vector<pair<int, int>>>& adj, int start) {
	vector<bool> visited(adj.size());
	stack<pair<int, int>> stk{};
	stk.push({start, 0});
	visited[start] = true;
	cout << start << "->";

	int maxl = INT_MIN;

	while (!stk.empty()) {
		pair<int, int> p = stk.top();
		stk.pop();
		cout << p.first << "->";
		maxl = max(maxl, p.second);
		for (const pair<int, int>& x: adj[p.first]) {
			if (!visited[x.first]) {
				stk.push({x.first, p.second + x.second});
				visited[x.first] = true;
			}
		}
	}
	cout << maxl << '\n';

	return maxl;
}

int traverse2(const vector<vector<pair<int, int>>>& adj, int idx, vector<bool>& visited) {
	int maxl = 0;
	for (const pair<int, int>& x: adj[idx]) {
		if (!visited[x.first]) {
			visited[x.first] = true;
			maxl = max(maxl, x.second + traverse2(adj, x.first, visited));
			visited[x.first] = false;
		}
	}

	return maxl;
}

void solve() {
	int v = nxt(), e = nxt();
	vector<vector<pair<int, int>>> adj(v + 1);

	for (int i = 0; i < e; i++) {
		int x = nxt(), y = nxt(), l = nxt();
		adj[x].push_back({y, l});
		adj[y].push_back({x, l});
	}

	/* for (int i = 1; i < v; i++) {
		sort(all(adj[v]), [&](pair<int, int> p1, pair<int, int> p2) {
				return p1.second > p2.second;
				});
	} */

	int maxl = INT_MIN;
	vector<bool> visited(v + 1, false);
	for (int i = 1; i <= v; i++) {
		visited[i] = true;
		maxl = max(maxl, traverse2(adj, i, visited));
		fill(all(visited), false);
	}

	cout << maxl << '\n';
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

