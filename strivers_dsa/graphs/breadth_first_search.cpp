#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <queue>

using namespace std;

int visited[100];  // visited is must for dfs/bfs
queue<int> q;  // a queue is used to do breadth first search traversal

void bfs(const vector<int>* const adj, int start) {
	visited[start] = 1;
	cout << start << " ";
	for (int x: adj[start]) {
		if (0 == visited[x])
			q.push(x);
	}
	while (!q.empty()) {  // check the neighbours
		int x = q.front();
		q.pop();
		if (0 == visited[x]) {
			// check is needed, in case a neighbour is not visited
			// but is present in queue. So, having this check will
			// prevent traversing the same node again here
			bfs(adj, x);
		}
	}
}

// iterative version
/* adj: adjacency list
 * n: no. of nodes
 */
void bfs_iterative(const vector<int>* const adj, int n) {
	int visited[n + 1];  // do this if graph is starting from 1 (instead of 0)
	memset(visited, 0, n + 1);
	queue<int> q{};
	// starting with 1, since input is start "1" (and not 0) based graph
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int x = q.front();  // now this will be the new start
		q.pop();
		cout << x << " ";  // can store in data structure and return
		// it's the same thing as in recursive version, you are visiting once only

		for (int x: adj[x]) {
			if (0 == visited[x]) {  // the nodes aren't visited
				visited[x] = 1;
				q.push(x);
			}
		}
	}
}

int main(void) {
	int n{}, e{};
	memset(visited, 0, 100);

	cin >> n >> e;
	vector<int> adj[n + 1];
	for (size_t i{}; i < e; i++) {
		int x{}, y{};
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);  // undirected & unweighted graph
	}

	// bfs(adj, 1);  // starting node: 1
	bfs_iterative(adj, n);  // starting node: 1
	cout << endl;

	return 0;
}

/* input:
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
