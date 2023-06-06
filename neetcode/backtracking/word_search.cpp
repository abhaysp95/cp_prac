#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		bool exist(vector<vector<char>>& board, string word) {
			for (size_t i = 0; i < board.size(); i++) {
				for (size_t j = 0; j < board[0].size(); j++) {
					vector<vector<bool>> visited(board.size(),
							vector<bool>(board[0].size(), false));
					if (_does_word_exist(board, word, 0, 0, 0, visited)) {
						return true;
					}
				}
			}

			return false;
		}

	private:
		bool _does_word_exist(const vector<vector<char>>& board, const string word,
				int i, int j, size_t c, vector<vector<bool>>& visited) {
			if (c == word.size()) {
				return true;  // word found
			}
			if (i < 0 || j < 0 || i == board.size() || j == board[0].size()
					|| word[c] != board[i][j] || visited[i][j]) {
				return false;
			}

			bool status = false;
			visited[i][j] = true;
			status = _does_word_exist(board, word, i - 1, j, c + 1, visited)
				|| _does_word_exist(board, word, i + 1, j, c + 1, visited)
				|| _does_word_exist(board, word, i, j - 1, c + 1, visited)
				|| _does_word_exist(board, word, i, j + 1, c + 1, visited);
			visited[i][j] = false;

			return status;
		}


		// I think this one failed few hidden test case (reason not clear to me)
		bool _does_word_exist_second(const vector<vector<char>>& board, const string word,
				int i, int j, size_t c, vector<vector<bool>>& visited) {
			if ((word.size() == 1 && word[0] == board[i][j]) || c == word.size()) {
				return true;
			}
			if (word[c] != board[i][j]) {
				return false;
			}

			bool status = false;
			for (int drow = -1; drow <= 1; drow++) {
				for (int dcol = -1; dcol <= 1; dcol++) {
					if (drow != dcol && (drow == 0 || dcol == 0)) {
						int x = i + drow;
						int y = j + dcol;
						if ((x >= 0 && x < board.size())
								&& (y >= 0 && y < board.size()) && !visited[x][y]) {
							visited[x][y] = true;
							status |= _does_word_exist_second(board, word, x, y, c + 1, visited);
							visited[x][y] = false;
						}
					}
				}
			}

			return status;
		}
};

/** TODO: do these too
 * word search 2
 */
