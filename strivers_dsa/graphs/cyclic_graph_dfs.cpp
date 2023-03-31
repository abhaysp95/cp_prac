#include <bits/stdc++.h>

using namespace std;

bool detect_cycle(const vector<int>* const adj, int n) {
	int visited[n + 1];
	for (size_t i{}; i <= n; i++) {
		visited[i] = 0;
	}
	stack<pair<int, int>> stk{};

	visited[1] = 1;
	stk.push({1, -1});

	while (!stk.empty()) {
		auto cpair = stk.top();
		int cur_node = cpair.first;
		int parent = cpair.second;
		stk.pop();

		for (auto adj_node: adj[cur_node]) {
			if (!visited[adj_node]) {
				visited[adj_node] = 1;
				stk.push({adj_node, cur_node});
			} else if (adj_node != parent) {
				return true;  // cycle detected
			}
		}
	}

	return false;
}

bool detect_cycle(const vector<int>* const adj, int n, int* visited, int start) {
	stack<pair<int, int>> stk{};

	visited[start] = 1;
	stk.push({start, -1});

	while (!stk.empty()) {
		auto cpair = stk.top();
		int cur_node = cpair.first;
		int parent = cpair.second;
		stk.pop();

		for (auto adj_node: adj[cur_node]) {
			if (!visited[adj_node]) {
				visited[adj_node] = 1;
				stk.push({adj_node, cur_node});
			} else if (adj_node != parent) {
				// cout << "cur, parent, adj" << cur_node << parent << adj_node << '\n';
				return true;  // cycle detected
			}
		}
	}

	return false;
}

int main(void) {
	int n{}, e{};
	cin >> n >> e;

	vector<int> adj[n + 1];

	int x{}, y{};
	for (size_t i{}; i < e; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// cout << (detect_cycle(adj, n) ? "true" : "false") << endl;
	//
	// example: cycle detection in connected components
	int visited[n + 1];
	for (size_t i{}; i <= n; i++) {
		visited[i] = 0;
	}
	bool cycle_detected{false};
	for (size_t i{1}; i <= n; i++) {
		if (!visited[i]) {
			if (detect_cycle(adj, n, visited, i)) {
				cycle_detected = true;
				break;
			}
		}
	}
	cout << (cycle_detected ? "true" : "false") << endl;


	return 0;
}

/** inputs:
 * example given in file: cyclic_graph_bfs.cpp
 */
