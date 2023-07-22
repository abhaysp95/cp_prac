#include <bits/stdc++.h>

using namespace std;

#define sz(a) ((int)a.size())

// some hidden test case is giving wrong answer for this solution (will fix later)

bool dfs(const vector<vector<int>>& adj, int x, vector<bool>& vis, vector<int>& temp) {
	if (vis[x]) {
		vector<int> t2{};
		int i = 0;
		for (; i < sz(temp); i++) {
			if (temp[i] == x) break;
		}
		for (int j = i; j < sz(temp); j++) {
			t2.push_back(temp[j]);
		}
		temp = t2;
		return false;
	}

	vis[x] = true;
	temp.push_back(x);

	bool status = true;
	for (const int ch: adj[x]) {
		if (!status) break;
		status &= dfs(adj, ch, vis, temp);
	}

	return status;
}

int main(void) {
	int n;
	cin >> n;

	vector<vector<int>> adj(n + 1, vector<int>{});
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		adj[i + 1].push_back(x);
	}

	vector<bool> visited(n + 1, false);
	vector<int> temp{};
	bool status = true;
	for (int i = 1; i <= n; i++) {
		if (!status) break;
		temp.clear();
		status &= dfs(adj, i, visited, temp);
	}

	for (int i = 0; i < sz(temp); i++) {
		if (i + 1 < sz(temp)) {
			cout << temp[i] << " ";
		} else cout << temp[i] << '\n';
	}

	return 0;
}
