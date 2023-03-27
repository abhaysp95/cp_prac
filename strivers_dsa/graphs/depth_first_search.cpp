#include <bits/stdc++.h>
#include <stack>

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

void dfs_iterative(const vector<int>* const adj, int n) {
	stack<int> stk{};
	int vstd[n + 1];

	for (size_t i = 0 ; i < n + 1; i++) {
		vstd[i] = 0;
	}

	stk.push(1);
	vstd[1] = 1;

	while (!stk.empty()) {
		auto x = stk.top();
		stk.pop();
		cout << x << " ";

		for (auto k: adj[x]) {
			if (!vstd[k]) {
				vstd[k] = 1;
				stk.push(k);
			}
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

	// dfs(adj, 1);
	dfs_iterative(adj, n);
	cout << endl;

	return 0;
}

/** input:
 * 9 9
 * 1 2
 * 1 6
 * 2 3
 * 2 4
 * 4 5
 * 5 8
 * 6 7
 * 6 9
 * 7 8
 */
