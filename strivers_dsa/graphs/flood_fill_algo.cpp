#include <bits/stdc++.h>
#include <utility>

using namespace std;

void print_matrix(const vector<vector<int>>& matrix) {
	if (matrix.empty()) return;
	for (size_t i = 0; i < matrix.size() - 1; i++) {
		for (auto x: matrix[i]) {
			cout << x << " ";
		}
		cout << '\n';
	}
	for (auto x: matrix[matrix.size() - 1]) {
		cout << x << " ";
	}
	cout << endl;

}

void flood_fill(vector<vector<int>>& mat, int sr, int sc, int new_color) {
	vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
	queue<pair<int, int>> q{};

	int start_value = mat[sr][sc];

	q.push(make_pair(sr, sc));
	visited[sr][sc] = 1;

	auto valid_push = [&](int x, int y) {
		if ((x >= 0 && x < mat.size()) && (y >= 0 && y < mat[0].size())) {
			if (!visited[x][y] && start_value == mat[x][y]) {
				visited[x][y] = 1;
				q.push(make_pair(x, y));
			}
		}
	};

	while (!q.empty()) {
		auto cpair = q.front();
		int x = cpair.first;
		int y = cpair.second;
		q.pop();

		mat[x][y] = new_color;

		valid_push(x - 1, y);
		valid_push(x, y + 1);
		valid_push(x + 1, y);
		valid_push(x, y - 1);
	}
}

int main() {

	int n{}, e{};
	cin >> n >> e;

	vector<vector<int>> mat(n, vector<int>{});

	int x{};
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < e; j++) {
			cin >> x;
			mat[i].push_back(x);
		}
	}

	int sr{}, sc{}, new_color{};
	cin >> sr >> sc >> new_color;

	flood_fill(mat, sr, sc, new_color);
	print_matrix(mat);
}

/** inputs
 * 3 3
 * 1 1 1
 * 1 1 0
 * 1 0 1
 * 1 1 2
 *
 * explaination: row: 3, col: 3
 * then matrix:
 * 1 1 1
 * 1 1 0
 * 1 0 1
 * sr: 1, sc: 1, new_color: 2
 * --------------------
 * 5 4
 * 1 1 1 0
 * 1 1 0 1
 * 1 0 1 1
 * 1 1 1 0
 * 1 0 1 0
 * 2 0 2
 */
