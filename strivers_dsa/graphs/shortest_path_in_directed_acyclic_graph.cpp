#include <bits/stdc++.h>

using namespace std;

vector<int> shortest_path(vector<vector<pair<int, int>>>& adj) {
	vector<int> dist(adj.size(), INT_MAX);
	queue<int> q{};
	q.push(0);  // starting node is 0
	dist[0] = 0;

	while (!q.empty()) {
		int cnode = q.front();
		q.pop();

		for (const pair<int, int> x: adj[cnode]) {
			if (dist[cnode] + 1 < dist[x.first]) { // in case of non-visited node, this
											 // condition should always be true
											 // (unless, dist[cnode] is INT_MAX(-1))
				dist[x.first] = dist[cnode] + x.second;
				q.push(x.first);
			}
		}
	}

	return dist;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	int x, y, w;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}

	vector<int> res = shortest_path(adj);
	for (const int x: res) {
		cout << (x == INT_MAX ? -1 : x) << " ";
	}
	cout << endl;
}
