#include <bits/stdc++.h>

using namespace std;

using vvec = vector<vector<int>>;
using vec = vector<int>;

// recursively (memoized way)
size_t get_ways_in_maze(const vvec& maze, size_t r, size_t c, vvec& space) {
	if (r == maze.size() - 1 && c == maze[0].size() - 1) {
		return 1;
	} else if (r >= maze.size() || c >= maze[0].size()) {
		return 0;
	}

	if (space[r][c] != -1) {
		return space[r][c];
	}

	if (maze[r][c] != -1) {
		return space[r][c] = get_ways_in_maze(maze, r + 1, c, space)
			+ get_ways_in_maze(maze, r + 1, c + 1, space)
			+ get_ways_in_maze(maze, r, c + 1, space);
	}

	return space[r][c] = 0;
}

// maze solved (tabulation way)
size_t get_ways_in_maze_tabulation(const vvec& maze) {
	if (maze.empty() || maze[0].empty()) return 0;

	vvec space(maze.size(), vec(maze[0].size(), 0));

	for (size_t i = 0; i < maze.size(); i++) {
		for (size_t j = 0; j < maze[0].size(); j++) {
			if (i == 0 || j == 0) {
				space[i][j] = (maze[i][j] == -1 ? 0 : 1);
				continue;
			}
			if (maze[i][j] == -1) {
				space[i][j] = 0;
			} else {
				space[i][j] = space[i -1][j] + space[i - 1][j - 1] + space[i][j - 1];
			}
		}
	}

	/* for (vec& v: space) {
		for (int x: v) {
			cout << x <<  " ";
		}
		cout << endl;
	} */

	return space[maze.size() - 1][maze[0].size() - 1];
}

int main(void) {
	size_t r{}, c{}, t{};
	cin >> r >> c >> t;

	vvec maze(r, vec(c, 0));
	while (t--) {
		size_t i{}, j{};
		cin >> i >> j;
		maze[i][j] = -1;
	}

	/* vvec space(r, vec(c, -1));
	cout << get_ways_in_maze(maze, 0, 0, space) << endl; */
	cout << get_ways_in_maze_tabulation(maze) << endl;

	return 0;
}
