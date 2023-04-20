#include <bits/stdc++.h>

using namespace std;
using vecstr = vector<vector<char>>;

class Solution {
	public:
		int totalNQueens(int n) {
			vecstr board(n, vector<char>(n, '.'));

			size_t count{};
			nqueens(board, n, 0, count);

			return count;
		}

	private:
		void nqueens(vecstr& board, const int n, int i, size_t& count) {
			if (i == n) {
				count++;
				return;
			}
			// cout << "came: i: " << i << endl;
			for (int j = 0; j < n; j++) {
				if (check(board, i, j, n)) {
					// cout << "check passed: i, j: " << i << ", " << j << endl;
					board[i][j] = 'Q';
					nqueens(board, n, i + 1, count);
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

	cout << sol.totalNQueens(4) << endl;

	return 0;
}
