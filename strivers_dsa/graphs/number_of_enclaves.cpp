// 1 is land, 0 is water. move on land cells in 4 directions or walk of the boundary of grid. Find out no. of land cells in grid which we can't walk off the boundary of the grid in any number of moves

#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;
using vec2d = vector<vector<int>>;

void print_matrix(const vec2d& matrix) {
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

int fill_land_cells_connecting_boundary(const vec2d& mat, vec2d& visited, stack<pair<int, int>>& stk) {
	int land_reached{};
	size_t r{mat.size()}, c{mat[0].size()};

	while (!stk.empty()) {
		auto point = stk.top();
		stk.pop();
		int x{point.first}, y{point.second};

		for (int drow{-1}; drow <= 1; drow++) {
			for (int dcol{-1}; dcol <= 1; dcol++) {
				// check if it's the neighbour (4 direction only)
				if ((0 == drow || 0 == dcol) && (drow != dcol)) {
					int i = x + drow, j = y + dcol;
					if ((i >= 0 && i < r) && (j >= 0 && j < c)  // check if it is within boundary
							&& (1 == mat[i][j])  // it's the land cell
							&& !visited[i][j]) {   // and the land cell isn't visited
						stk.push({i, j});
						visited[i][j] = 1;
						land_reached++;
					}
				}
			}
		}
	}

	return land_reached;
}

int main(void) {
	size_t r{}, c{};
	cin >> r >> c;

	vec2d mat(r, vector<int>(c, 0));

	for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			cin >> mat[i][j];
		}
	}

	// land cells at the boundary (yes, we're solving in reverse direction)
	stack<pair<int, int>> stk{};
	vec2d visited(r, vector<int>(c, 0));
	size_t num_land_cells{};
	size_t land_cells_in_boundary{};
	for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			if ((0 == i || 0 == j || r - 1 == i || c - 1 == j) && mat[i][j] == 1) {  // you're in boundary and it's land cell
				land_cells_in_boundary++;
				visited[i][j] = 1;
				stk.push({i, j});
			}
			if (mat[i][j]) num_land_cells++;  // irrespective of position, if it's land cell, increase the count
		}
	}

	print_matrix(mat);
	cout << "-------------\n";

	size_t lands_reached = land_cells_in_boundary + fill_land_cells_connecting_boundary(mat, visited, stk);

	print_matrix(visited);

	cout << "num_land_cells, land_cells_in_boundary, lands_reached: "
		<< num_land_cells << ", " << land_cells_in_boundary << ", " << lands_reached << endl;

	cout << "count: " << num_land_cells - lands_reached << endl;

	return 0;
}

/** inputs:
  * 5 4
  * 0 0 0 1
  * 0 1 1 0
  * 0 1 1 0
  * 0 0 0 1
  * 0 1 1 0
  * --------
  * 5 4
  * 0 0 1 1
  * 0 1 1 0
  * 0 1 1 0
  * 0 0 0 1
  * 0 1 1 0
  */
