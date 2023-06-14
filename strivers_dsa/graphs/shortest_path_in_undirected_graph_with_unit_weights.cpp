#include <bits/stdc++.h>

using namespace std;

vector<size_t> shortest_path(const vector<vector<int>>& adj, const int src) {
	vector<size_t> res(adj.size(), INT_MAX);
	// vector<bool> visited(adj.size(), false);
	/* queue<pair<int, size_t>> q{};

	q.push({src, 0}); */
	/* visited[src] = true;
	res[src] = 0;

	while (!q.empty()) {
		const pair<int, size_t> p = q.front();
		q.pop();
		// res[p.first] = p.second;

		for (const int x: adj[p.first]) {
			if (!visited[x]) {
				visited[x] = true;
				q.push({x, p.second + 1});
				res[x] = min(res[x], p.second + 1);
			}
		}
	} */

	// NOTE: we can just use one array only, which would be res and it can also work as visited
	res[src] = 0;

	/* while (!q.empty()) {
		const pair<int, size_t> p = q.front();
		q.pop();

		for (const int x: adj[p.first]) {
			if (res[x] == INT_MAX) {
				q.push({x, p.second + 1});
			}
			res[x] = min(res[x], p.second + 1);  // it's possible that you already visited a node once, but this time you may get low distance
		}
	} */

	// NOTE: no need of pair in queue also
	queue<int> q{};
	q.push(src);
	res[src] = 0;

	while (!q.empty()) {
		int cnode = q.front();
		q.pop();

		for (const int x: adj[cnode]) {
			if (res[cnode] + 1 < res[x]) {
				res[x] = res[cnode] + 1;
				q.push(x);
			}
		}
	}

	return res;
}

int main(void) {
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>{});

	int x = 0, y = 0;
	for (size_t i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int src = 0;
	cin >> src;

	vector<size_t> res = shortest_path(adj, src);
	for (const int x: res) {
		cout << (x == INT_MAX ? -1 : x) << " ";
	}
	cout << endl;
}

/**
 * input:
 * n, m
 * (pair)
 * src
 *-------------------------
 * 9 11
 * 0 1
 * 0 3
 * 1 3
 * 1 2
 * 2 6
 * 3 4
 * 4 5
 * 5 6
 * 6 7
 * 6 8
 * 7 8
 * 0
 */
