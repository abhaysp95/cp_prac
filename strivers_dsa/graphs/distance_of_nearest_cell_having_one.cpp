#include <bits/stdc++.h>
#include <queue>

using namespace std;

using vec2d = vector<vector<int>>;
using cdl = pair<pair<int, int>, size_t>;

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

// using bfs (whenever you've to get to work with your neighbours use bfs)
int find_nearest(const vec2d& mat, size_t x, size_t  y) {
	size_t r{mat.size()}, c{mat[0].size()};
	queue<cdl> q{}; // {{x, y}, level}
	vec2d visited(r, vector<int>(c, 0));
	visited[x][y] = 1;
	q.push({{x, y}, 0});

	auto validate_action = [&](int i, int j, size_t l) {
		if ((i >= 0 && i < r) && (j >= 0 && j < c)) {
			if (mat[i][j] == 1) {
				return l;
			} else {
				if (!visited[i][j]) {
					q.push({{i, j}, l});
					visited[i][j] = 1;
				}
			}
		}
		return static_cast<size_t>(0);
	};

	while (!q.empty()) {
		auto my_pair = q.front();
		q.pop();
		int i{my_pair.first.first}, j{my_pair.first.second};
		size_t l{my_pair.second};

		for (int drow{-1}; drow <= 1; drow++) {
			for (int dcol{-1}; dcol <= 1; dcol++) {
				// diagonal neighbours not allowed
				// any one of them is zero, and they both are not same
				if ((0 == drow || 0 == dcol) && (drow != dcol)) {
					size_t res = validate_action(i + drow, j + dcol, l + 1);
					if (res) return res;
				}
			}
		}

	}

	return 0;
}

void find_nearest_second_time(const vec2d& mat, queue<cdl>& q, vec2d& visited, vec2d& res) {
	size_t r{mat.size()}, c{mat[0].size()};
	while (!q.empty()) {
		auto my_pair = q.front();
		q.pop();
		int i{my_pair.first.first}, j{my_pair.first.second};
		size_t l{my_pair.second};

		for (int drow{-1}; drow <= 1; drow++) {
			for (int dcol{-1}; dcol <= 1; dcol++) {
				if ((0 == drow || 0 == dcol) && (drow != dcol)) {
					i += drow, j+= dcol;
					if ((i >= 0 && i < r) && (j >= 0 && j < c)) {
						if (!visited[i][j] && 0 == mat[i][j]) {
							visited[i][j] = 1;
							q.push({{i, j}, l + 1});
							res[i][j] = l + 1;
						} else if (0 == mat[i][j]) {
							// you were initially 0, but you're already visited it's possible
							// that somebody else is nearer than the distance you've stored
							if (l + 1 < res[i][j]) {
								res[i][j] = l + 1;
							}
						}
					}
				}
			}
		}
	}
}

int main(void) {
	size_t r{}, c{};
	cin >> r >> c;

	// this is supposed to be a binary matrix
	vec2d mat(r, vector<int>(c, 0));

	for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			cin >> mat[i][j];
		}
	}
	vec2d res(r, vector<int>(c, 0));

	// This approach works like this:
	// if there's 1, the distance is 0
	// if there's 0, go find out who is your nearest one
	// this approach needs seperate "visited" matrix
	/* for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			if (0 == mat[i][j]) {
				res[i][j] = find_nearest(mat, i, j);
			} else {
				res[i][j] = 0;
			}
		}
	} */

	// but, there's another approach (using bfs again)
	// find all 1's and give them job, to go and fill out the zero's out
	// there by how distance they are from you
	// this approach will use common "visited"

	queue<cdl> q{};
	vec2d visited(r, vector<int>(c, 0));
	for (size_t i{}; i < r; i++) {
		for (size_t j{}; j < c; j++) {
			if (1 == mat[i][j]) {
				q.push({{i, j}, 0});
				visited[i][j] = 1;
				res[i][j] = 0;
			}
		}
	}

	find_nearest_second_time(mat, q, visited, res);

	print_matrix(res);

	return 0;
}

/** inputs:
 * 3 3
 * 1 0 1
 * 1 1 0
 * 1 0 0
 * ---------
 * 4 3
 * 0 1 1 0
 * 1 1 0 0
 * 0 0 1 1
 */
