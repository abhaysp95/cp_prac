#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// using 2D array
// if the input (graph) is weighted, store the weights instead of 1 in matrix
vector<vector<int>> matrix_method(int n, vector<pair<int, int>>& edges) {
	vector<vector<int>> vec2d{};
	vec2d.resize(n, vector<int>(n, 0));

	for (size_t i{}; i < edges.size(); i++) {
		auto x{edges[i].first}, y{edges[i].second};
		vec2d[x - 1][y - 1] = 1;
		vec2d[y - 1][x - 1] = 1;
	}

	return vec2d;
}

// if graph is weighted, use unordered_map<int, vector<pair<int>>> data
// structure for simplicity sake, we can also use "vector<int> adj[n];" which
// means n times vector<int> and thus for weighted graph, adjacency list would
// be "vector<pair<int, int>> adj[n];"
unordered_map<int, vector<int>> adjacency_list(int n, vector<pair<int, int>>& edges) {
	unordered_map<int, vector<int>> umap{};

	for (size_t i{}; i < edges.size(); i++) {
		auto x{edges[i].first}, y{edges[i].second};
		umap[x].push_back(y);
		umap[y].push_back(x);  // in case of directional graph, comment this line
	}

	return umap;
}

void print_array(vector<vector<int>>& arr) {
	if (arr.empty()) return;
	if (arr.size() == 1) {
		for (size_t i{}; i < arr[0].size(); i++) {
			cout << arr[0][i] << " ";
		}
	} else {
		for (size_t i{}; i < arr.size() - 1; i++) {
			for (size_t j{}; j < arr.size(); j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
		for (size_t i{}; i < arr[arr.size() - 1].size(); i++) {
			cout << arr[arr.size() - 1][i] << " ";
		}
		cout << endl;
	}
}

void print_adjacency_list(unordered_map<int, vector<int>>& umap) {
	auto iter_vec = [](int x, vector<int>& vec) {
		cout << x << " -> ";
		for (int x: vec) {
			cout << x << " ";
		}
	};

	// get the keys out of map
	vector<int> keys(umap.size());
	transform(umap.begin(), umap.end(), keys.begin(), [](auto pair) { return pair.first; });

	vector<vector<int>> values(umap.size());
	transform(umap.begin(), umap.end(), values.begin(), [](auto pair) { return pair.second; });

	if (umap.empty()) return;
	else if (umap.size() == 1) {
		iter_vec(keys[0], values[0]);
	}
	for (size_t i{}; i < umap.size() - 1; i++) {
		iter_vec(keys[i], values[i]);
		cout << '\n';
	}

	iter_vec(keys[keys.size() - 1], values[umap.size() - 1]);
	cout << endl;
}

int main() {
	int n{}, e{};
	cin >> n >> e;

	vector<pair<int, int>> edges;
	int x{}, y{};
	for (size_t i{}; i < e; i++) {
		cin >> x >> y;
		edges.emplace_back(x, y);
	}

	auto adj_list = adjacency_list(n, edges);
	print_adjacency_list(adj_list);

	return 0;
}
