#include <bits/stdc++.h>
#include <queue>
#include <utility>

using namespace std;

/* bool detect_cycle(const vector<int>* const adj, int n) {
	vector<pair<int, int>> visited{static_cast<size_t>(n + 1), {0, 0}};
	queue<pair<int, int>> q{};

	q.push({1, 0});
	visited[1] = {1, 0};

	while (!q.empty()) {
		auto my_pair = q.front();
		q.pop();
		auto idx = my_pair.first;
		auto level = my_pair.second;

		for (auto x: adj[idx]) {
			if (!visited[x].first) {
				q.push({x, level + 1});
				visited[x] = {x, level + 1};
	 		} else {  // if the neighbour is already visited, check if it's done by the same level
				if (visited[x].second == level + 1) {
					// cout << "idx, x, visited[x].second, level: " << idx << x << visited[x].second << level << '\n';
					return true;  // cycle detected
				}
			}
		}
	}

	return false;
} */

bool detect_cycle(const vector<int>* const adj, int n) {
	int visited[n + 1];
	for (size_t i{}; i <= n; i++) {
		visited[i] = 0;
	}
	queue<pair<int, int>> q{};  // { current_node, parent }
	q.push({1, -1});  // parent unknown
	visited[1] = 1;

	while (!q.empty()) {
		auto cpair = q.front();
		int cur_node = cpair.first;
		int parent = cpair.second;
		q.pop();

		for (auto adj_node: adj[cur_node]) {
			if (!visited[adj_node]) {
				visited[adj_node] = 1;
				q.push({adj_node, cur_node});
			} else if (adj_node != parent) { // the neighbouring node is already
											 // visited and is not my parent,
											 // thus cycle
				return true;
			}
		}
	}

	return false;
}
int main(void) {
	int n{}, e{};
	cin >> n >> e;

	int x{}, y{};
	vector<int> adj[n + 1];
	for (size_t i{}; i < e; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << "cycle detected: " << (detect_cycle(adj, n) ? "true" : "false") << endl;

	return 0;
}

/** inputs:
 * 7 7
 * 1 2
 * 1 3
 * 2 5
 * 3 4
 * 3 6
 * 5 7
 * 6 7
 * --------
 * 7 7
 * 1 2
 * 1 3
 * 2 5
 * 3 4
 * 3 6
 * 5 7
 * 6 4
 */
