#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

size_t lcs_recursive(const string& l1, const string& l2, int x, int y) {
	if (x ==  0 || y == 0) {
		return 0;
	}

	// if matched
	if (l1[x - 1] == l2[y - 1]) {
		printf("1 + lcs(%d, %d)\n", x - 1, y - 1);
		return 1 + lcs_recursive(l1, l2, x - 1, y - 1);
	}

	// not matched
	printf("max(lcs(%d, %d), lcs(%d, %d))\n", x, y - 1, x - 1, y);
	return max(lcs_recursive(l1, l2, x, y - 1), lcs_recursive(l1, l2, x - 1, y));
}

size_t lcs_memoization(const string& l1, const string& l2, int x, int y, vector<vector<int>>& space) {
	if (x == 0 || y == 0) {
		space[x][y] = 0;
		return 0;
	}

	if (space[x][y] != -1) {
		return space[x][y];
	}

	if (l1[x - 1] == l2[y - 1]) {
		return space[x][y] = 1 + lcs_memoization(l1, l2, x - 1, y - 1, space);
	}

	return space[x][y] = max(lcs_memoization(l1, l2, x, y - 1, space), lcs_memoization(l1, l2, x - 1, y, space));
}

size_t lcs_memoization_round2(const string& l1, const string& l2, size_t x, size_t y, vector<vector<int>>& space) {
	if (x == l1.size() || y == l2.size()) {
		return 0;
	}

	if (space[x + 1][y + 1] != -1) {
		return space[x + 1][y + 1];
	}

	if (l1[x] == l2[y]) {
		return space[x + 1][y + 1] = 1 + lcs_memoization_round2(l1, l2, x + 1, y + 1, space);
	}

	return space[x + 1][y + 1] = max(lcs_memoization_round2(l1, l2, x, y + 1, space),
			lcs_memoization_round2(l1, l2, x + 1, y, space));
}

void print_arr(const vector<vector<int>>& space) {
	for (size_t i = 0; i < space.size(); i++) {
		for (size_t j = 0; j < space[0].size(); j++) {
			cout << space[i][j] << " ";
		}
		cout << '\n';
	}
	cout << endl;
}

size_t lcs_tabulation(const string& l1, const string& l2) {

	vector<vector<int>> space(l1.size() + 1, vector<int>(l2.size() + 1, -1));

	for (size_t i{}; i <= l1.size(); i++) {
		for (size_t j{}; j <= l2.size(); j++) {
			if (i == 0 || j == 0) space[i][j] = 0;
			else if (l1[i - 1] == l2[j - 1]) {
				space[i][j] = 1 + space[i - 1][j - 1];
			} else {
				space[i][j] = max(space[i - 1][j], space[i][j - 1]);
			}
		}
	}

	print_arr(space);

	size_t i = l1.size(), j = l2.size();
	string res{};
	while (i != 0 && j != 0) {
		cout << "(i, j)" << i << ", " << j << '\n';
		if (l1[i - 1] == l2[j - 1]) {  // strings are at one more difference
			res += l1[i - 1];
			i--, j--;
		} else {
			if (space[i - 1][j] == space[i][j - 1]) {
				i--;
			} else if (space[i - 1][j] > space[i][j - 1]) {
				i--;
			} else {
				j--;
			}
		}
	}

	// if you want it in correct order (start -> end), reverse the res, or do
	// res = l1[i - 1] + res; (above)
	cout << res << endl;

	return space[l1.size()][l2.size()];
}

int main(void) {

	string l1{"BIRD"}, l2{"BEARD"};
	// cout << lcs_recursive(l1, l2, l1.size(), l2.size()) << endl;

	// vector<vector<int>> space(l1.size() + 1, vector<int>(l2.size() + 1, -1));
	// cout << lcs_memoization(l1, l2, l1.size(), l2.size(), space) << endl;
	// cout << lcs_memoization_round2(l1, l2, 0, 0, space) << endl;

	/* print_arr(space);
	cout << endl; */

	cout << lcs_tabulation(l1, l2) << endl;

	return 0;
}
