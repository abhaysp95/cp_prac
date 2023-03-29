#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using vec2 = vector<vector<int>>; /* matrix */
using cds = pair<int, int>;  /* co-ordinates */
using cdst = pair<cds, int>;  /* co-ordinates with generation count */

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

/* easy to work it one used with BFS, because each level of traversal could be
 * considered as iteration taken to rot the orange */
int rotten_oranges(vec2& mat) {
	/* visited will help in traversal, and will also show that oranges are now rotten */
	vec2 visited(mat.size(), vector<int>(mat[0].size(), 0));
	queue<cdst> q{};
	int max_iter{-1};

	/* get the rotten oranges for starting the traversal (first gen) */
	for (size_t i = 0; i < mat.size(); i++) {
		for (size_t j = 0; j < mat[0].size(); j++) {
			if (2 == mat[i][j]) {
				visited[i][j] = 2;
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	auto validate_push = [&](int i, int j, int t) {
		if ((i >= 0 && i < mat.size()) && (j >= 0 && j < mat.size()) && mat[i][j] == 1) {
			if (!visited[i][j]) { // that means don't traverse for already
								  // rotten orange again (some neighbour
								  // had already rotten this orange)
				max_iter = max(max_iter, t);
				visited[i][j] = 2;
				q.push(make_pair(make_pair(i, j), t));
			}
		}
	};

	/* start the traversal */
	while (!q.empty()) {
		cdst pdlt = q.front();
		q.pop();
		cds pd = pdlt.first;
		// mat[pd.first][pd.second] = 2;  /* now rotten */

		validate_push(pd.first - 1, pd.second, pdlt.second + 1);
		validate_push(pd.first + 1, pd.second, pdlt.second + 1);
		validate_push(pd.first, pd.second - 1, pdlt.second + 1);
		validate_push(pd.first, pd.second + 1, pdlt.second + 1);
	}

	return max_iter;
}

int main(void) {
	int r{}, c{};
	cin >> r >> c;

	int x{};
	vector<vector<int>> mat(r, vector<int>{});
	for (size_t i = 0; i < r; i++) {
		for (size_t j = 0; j < c; j++) {
			cin >> x;
			mat[i].push_back(x);
		}
	}

	cout << "max iter: " << rotten_oranges(mat) << endl;
	print_matrix(mat);

	return 0;
}

/** inputs:
 * 3 3
 * 0 1 2
 * 0 1 1
 * 2 1 1
 * -----
 * 3 3
 * 0 1 2
 * 0 1 2
 * 2 1 1
 */
