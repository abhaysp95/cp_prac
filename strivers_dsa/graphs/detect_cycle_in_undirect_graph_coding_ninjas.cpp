#include <bits/stdc++.h>

using namespace std;

bool bfs(const vector<vector<int>>&, int, vector<bool>&);

int main(void) {
	int V, E;
	cin >> V >> E;

	vector<vector<int>> adj(V, vector<int>{});
	for (size_t i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<bool> visited(V, false);
	bool cycle_found = false;

	for (size_t i = 0; i < V; i++) {
		if (!visited[i] && bfs(adj, i, visited)) {
			cycle_found = true;
			break;
		}
	}

	cout << (cycle_found ? "True" : "False") << endl;

	return 0;
}

bool bfs(const vector<vector<int>>& adj, int idx, vector<bool>& visited) {
	queue<pair<int, int>> q{};   // {node, parent}
	q.push({idx, -1});

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		int cnode = p.first;
		int cparent = p.second;

		for (const int x: adj[cnode]) {
			if (visited[x] && x != cparent) {
				return true;
			}
			if (!visited[x]) {
				visited[x] = true;
				q.push({x, cnode});
			}
		}
	}

	return false;
}
