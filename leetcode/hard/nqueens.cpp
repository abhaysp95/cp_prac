// https://leetcode.com/problems/n-queens/

#include <bits/stdc++.h>

using namespace std;
using vecstr = vector<string>;
using vec2dstr = vector<vector<string>>;

class Solution {
	public:
		vec2dstr totalNQueens(int n) {
			vecstr board(n, string(n, '.'));
			vec2dstr res{};

			nqueens(board, n, 0, res);

			return res;
		}

	private:
		void nqueens(vecstr& board, const int n, int i, vec2dstr& res) {
			if (i == n) {
				res.emplace_back(board);
				return;
			}
			// cout << "came: i: " << i << endl;
			for (int j = 0; j < n; j++) {
				if (check(board, i, j, n)) {
					// cout << "check passed: i, j: " << i << ", " << j << endl;
					board[i][j] = 'Q';
					nqueens(board, n, i + 1, res);
					board[i][j] = '.';
				}
			}
		}

		bool check(const vecstr& board, const int i, const int j, const int n) {
			if ((i >= 0 && i < n) && (j >= 0 && j < n)) {
				// queen attacks straight
				for (int x = 0; x < i; x++) {
					if (board[x][j] == 'Q' && x != i) {
						return false;
					}
				}
				for (int y = 0; y < j; y++) {
					if (board[i][y] == 'Q' && y != j) {
						return false;
					}
				}

				for (int x = i; x >= 0; x--) {
					int y1 = j - (i - x), y2 = j + (i - x);
					if (x != i) {
						if (y1 >= 0 && board[x][y1] == 'Q') {
							return false;
						}
						if (y2 < n && board[x][y2] == 'Q') {
							return false;
						}
					}
				}

				return true;
			}

			return false;
		}
};

int main(void) {
	Solution sol{};

	size_t x{};
	cout << "enter size: ";
	cin >> x;

	vec2dstr res = sol.totalNQueens(x);
	for (vecstr vs: res) {
		for (string s: vs) {
			cout << s << " ";
		}
		cout << '\n';
	}
	cout << endl;

	return 0;
}
