// https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(const vector<vector<int>>& adj, int idx, vector<bool>& visited) {
	queue<int> q{};
	vector<int> temp{};

	q.push(idx);
	visited[idx] = true;
	temp.push_back(idx);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (const int child: adj[x]) {
			if (!visited[child]) {
				visited[child] = true;
				temp.push_back(child);
				q.push(child);
			}
		}
	}

	return temp;
}

// definition provided in question
vector<int> BFS(int vertex, vector<pair<int, int>>& edges) {
	vector<vector<int>> adj(vertex, vector<int>{});

	for (const pair<int, int>& edge: edges) {
		adj[edge.first].push_back(edge.second);
		adj[edge.second].push_back(edge.first);
	}

	vector<bool> visited(vertex, false);
	vector<int> res{};

	for (int i = 0; i < vertex; i++) {
		if (!visited[i]) {
			vector<int> temp = bfs(adj, i, visited);
			res.insert(res.end(), temp.begin(), temp.end());
		}
	}

	return res;
}

int main(void) {
	int V, E;
	cin >> V >> E;

	vector<pair<int, int>> edges(V, pair<int, int>{});
	for (size_t i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		edges[i] = {x, y};
	}

	vector<int> result = BFS(V, edges);
	for (const int x: result) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
