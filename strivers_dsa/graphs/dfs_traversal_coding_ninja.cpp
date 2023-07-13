// https://www.codingninjas.com/studio/problems/dfs-traversal_630462?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& adj, int idx, vector<bool>& visited, vector<int>& temp) {
	visited[idx] = true;
	temp.push_back(idx);
	for (const int child: adj[idx]) {
		if (!visited[child]) dfs(adj, child, visited, temp);
	}
}

// definition provided by question
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
	vector<vector<int>> adj (static_cast<size_t>(V), vector<int>{});

	for (const vector<int>& edge: edges) {
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}

	vector<vector<int>> res{};
	vector<bool> visited(V, false);

	for (size_t i = 0; i < V; i++) {
		if (!visited[i]) {
			vector<int> temp{};
			dfs(adj, i, visited, temp);
			res.push_back(temp);
		}
	}

	return res;
}

int main(void) {
	int N, E;
	cin >> N >> E;

	vector<vector<int>> input{};

	for (size_t i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		input.push_back({x, y});
	}

	vector<vector<int>> result = depthFirstSearch(N, E, input);
	for (const vector<int>& component: result) {
		for (const int x: component) {
			cout << x << " " ;
		}
		cout << '\n';
	}

	cout << endl;

	return 0;
}
