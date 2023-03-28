#include <bits/stdc++.h>
#include <stack>
#include <utility>
#include <vector>

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


bool validate_coords(int x, int y, int r, int c) {
	return (x >= 0 && x < r) && (y >= 0 && y < c);
}



void number_of_islands(vector<vector<int>>& mat, int x, int y, vector<vector<int>>& visited) {
	stack<pair<int, int>> stk{};
	stk.push(make_pair(x, y));
	visited[x][y] = 1;

	auto vspush = [&](int j, int k) {
		if (validate_coords(j, k, mat.size(), mat[0].size())) {
			if (!visited[j][k] && mat[j][k]) {
				visited[j][k] = 1;
				stk.push(make_pair(j, k));
			}
		}
	};

	while (!stk.empty()) {
		auto cpair = stk.top();
		int j = cpair.first;
		int k = cpair.second;
		stk.pop();

		/** check in all 8 directions */
		/* vspush(j - 1, k);
		vspush(j - 1, k + 1);
		vspush(j, k + 1);
		vspush(j + 1, k + 1);
		vspush(j + 1, k);
		vspush(j + 1, k - 1);
		vspush(j, k - 1);
		vspush(j - 1, k - 1); */

		// better way to check out neighbours
		for (int drow = -1; drow <= 1; drow++) {
			for (int dcol = -1; dcol <= 1; dcol++) {
				vspush(j + drow, k + dcol);
			}
		}
	}
}


int main(void) {
	/** take input of island (essentially a matrix) */

	int r{}, c{}; // size of square matrix
	cin >> r >> c;

	vector<vector<int>> mat(5, vector<int>{});

	int x{};
	for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			cin >> x;
			mat[i].push_back(x);
		}
	}

	print_matrix(mat);

	vector<vector<int>> visited(r, vector<int>(c, 0));

	size_t count{};
	for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			if (!visited[i][j] && mat[i][j]) {
				number_of_islands(mat, i, j, visited);
				count++;
			}
		}
	}

	cout << "number of islands: " << count << endl;

	return 0;
}

/** inputs:
 * 5 5
 * 0 1 1 1 0
 * 0 0 1 1 0
 * 0 0 0 0 1
 * 0 1 0 0 0
 * 1 0 0 0 1
 *
 * 5 4
 * 0 1 1 0
 * 0 1 1 0
 * 0 0 1 0
 * 0 0 0 0
 * 1 1 0 1
 */
