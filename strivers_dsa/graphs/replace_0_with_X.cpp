#include <bits/stdc++.h>
#include <vector>

using namespace std;

using vec2d = vector<vector<char>>;

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

// using DFS (recursive)
void find_neighbour_zeroes(const vec2d& mat, vec2d& visited, pair<int, int> point) {
	size_t r{mat.size()}, c{mat[0].size()};
	int x{point.first}, y{point.second};
	visited[x][y] = '0';

	for (int drow{-1}; drow <= 1; drow++) {
		for (int dcol{-1}; dcol <= 1; dcol++) {
			if ((0 == drow || 0 == dcol) && (drow != dcol)) {  // only 4 directions
				int x = x + drow, y = y + dcol;  // don't do: x += drow, y += dcol; because x & y are out of this one's scope
												 // and value persist with every iteration
				// boundry check
				if ((x >= 0 && x < r)
						&& (y >= 0 && y < c)
						&& ('0' == mat[x][y])
						&& ('X' == visited[x][y])) {
					find_neighbour_zeroes(mat, visited, {x, y});
				}
			}
		}
	}
}

int main(void) {
	size_t r{}, c{};
	cin >> r >> c;

	vec2d mat(r, vector<char>());

	char x{};
	for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			cin >> x;
			mat[i].push_back(x);
		}
	}

	print_matrix(mat);

	vec2d visited(r, vector<char>(c, 'X'));
	// collect all 0s from the border
	for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			if ((i == 0 || i == r - 1 || j == 0 || j == c -1)
					&& ('0' == mat[i][j])
					&& ('X' == visited[i][j])) {
				find_neighbour_zeroes(mat, visited, {i, j});
			}
		}
	}

	// you got visited correct

	cout << "------------------\n";

	print_matrix(visited);


	return 0;
}
