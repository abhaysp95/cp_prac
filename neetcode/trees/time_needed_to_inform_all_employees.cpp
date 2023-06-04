// https://leetcode.com/problems/time-needed-to-inform-all-employees/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
			// make adjacency list
			unordered_map<int, vector<int>> adj{};
			for (size_t i = 0; i < manager.size(); i++) {
				adj[manager[i]].push_back(i);
			}

			size_t maxt = 0;
			// traverse bfs
			queue<pair<int, size_t>> q{};  // {worker id, time}
		q.push({headID, 0});

		while (!q.empty()) {
			const pair<int, size_t> tp = q.front();
			q.pop();
			maxt = max(maxt, tp.second);

			for (const int w: adj[tp.first]) {
				q.push({w, tp.second + informTime[tp.first]});
			}

			return maxt;
		}
};
