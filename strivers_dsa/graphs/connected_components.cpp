#include <bits/stdc++.h>
#include <queue>

// the question can also ask this as "no. of provinces"

using namespace std;

void bfs(const vector<int>* const adj, int n, int* visited, int start) {
	queue<int> q{};

	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		// cout << x <<  " ";

		for (auto k : adj[x]) {
			if (!visited[k]) {
				visited[k] = 1;
				q.push(k);
			}
		}
	}

}

int main(void) {
	int n{}, e{};
	cin >> n >> e;

	int visited[n + 1];

	for (size_t i{}; i < n + 1; i++) {
		visited[i] = 0;
	}

	vector<int> adj[n + 1]; // graph starts from 1
	for (size_t i{}; i < e; i++) {
		int x{}, y{};
		 cin >> x >> y;
		 adj[x].push_back(y);
		 adj[y].push_back(x);
	}

	size_t count{};
	for (int i{1}; i < n + 1; i++) {
		if (!visited[i]) {
			bfs(adj, n, visited, i);
			count++;
		}
	}

	cout << "connected components: " << count << endl;

	return 0;
}

/** inputs:
 * 9 7
 * 1 2
 * 2 3
 * 3 1
 * 3 4
 * 5 6
 * 6 7
 * 8 9
 */
