#include <bits/stdc++.h>

using namespace std;

int visited[100];

void dfs(const vector<int>* const adj, int start) {
	visited[start] = 1;
	cout << start << " ";

	for (int x: adj[start]) {
		if (!visited[x]) {
			dfs(adj, x);
		}
	}
}

int main() {
	int n{}, e{};
	cin >> n >> e;

	memset(visited, 0, 100);

	vector<int> adj[n + 1];  // graph starts from "1"
	for (size_t i{}; i < e; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(adj, 1);
	cout << endl;

	return 0;
}
