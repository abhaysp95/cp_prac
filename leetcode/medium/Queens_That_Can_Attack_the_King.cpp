// https://leetcode.com/problems/queens-that-can-attack-the-king/

#include <bits/stdc++.h>

using namespace std;
using veci = vector<int>;
using vecb = vector<bool>;
using vec2di = vector<vector<int>>;
using vec2db = vector<vector<bool>>;

class Solution {
#define SZ 8  // given in question

	public:
		vec2di queensAttackTheKing(vec2di& queens, veci& king) {
			vec2di res{};

			// create the board (makes it easy)
			vec2di board(SZ, veci(SZ, 0));
			// king is 2, queen is 1

			for (veci& queen: queens) {
				board[queen[0]][queen[1]] = 1;
			}
			board[king[0]][king[1]] = 2;

			const int kx = king[0], ky = king[1];
			if (!(min(kx, ky) >= 0 && max(kx, ky) < SZ)) {
				return res; // don't know what to do here (it's just wrong)
			}

			// check if queen is in my straight line of sight we
			// need separate above/below because in both directions,
			// there can be multiple queens, but we only need the
			// one who is directly attacking king above me (same
			// column)
			// above me (same column)
			for (int x = kx; x >= 0; x--) {
				if (1 == board[x][ky]) {
					veci v = {x, ky};
					res.push_back(v);
					break;  // already met a king
				}
			}
			// below me (same column)
			for (int x = kx; x < SZ; x++) {
				if (x != kx && 1 == board[x][ky]) {
					veci v = {x, ky};
					res.push_back(v);
					break;  // already met a king
				}
			}

			// left to me (same row)
			for (int y = ky; y >= 0; y--) {
				if (1 == board[kx][y]) {
					veci v = {kx, y};
					res.push_back(v);
					break;
				}
			}
			// right to me (same row)
			for (int y = ky; y < SZ; y++) {
				if (1 == board[kx][y]) {
					veci v = {kx, y};
					res.push_back(v);
					break;
				}
			}

			// check diagonals (above me)
			bool ld{false}, rd{false};
			for (int x = kx; x >= 0; x--) {
				int y1 = ky - (kx - x), y2 = ky + (kx - x);
				if (!ld) {
					if (y1 >= 0 && 1 == board[x][y1]) {
						veci v = {x, y1};
						res.push_back(v);
						ld = true;
					}
				}
				if (!rd) {
					if (y2 < SZ && 1 == board[x][y2]) {
						veci v = {x, y2};
						res.push_back(v);
						rd = true;
					}
				}
			}

			// check diagonals (below me)
			ld = false, rd = false;
			for (int x = kx; x < SZ; x++) {
				int y1 = ky - (x - kx), y2 = ky + (x - kx);
				if (!ld) {
					if (y1 >= 0 && 1 == board[x][y1]) {
						veci v = {x, y1};
						res.push_back(v);
						ld = true;
					}
				}
				if (!rd) {
					if (y2 < SZ && 1 == board[x][y2]) {
						veci v = {x, y2};
						res.push_back(v);
						rd = true;
					}
				}
			}

			return res;
		}

		vec2di queensAttackTheKing_shorter_version(vec2di& queens, veci& king) {
			vec2db board(SZ, vecb(SZ, false));
			vec2di res{};

			for (veci& queen: queens) {
				board[queen[0]][queen[1]] = true;
			}

			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (!i && !j) continue;
					int kx = king[0] + i, ky = king[1] + j;
					while (min(kx, ky) >= 0 && max(kx, ky) < SZ) {
						if (board[kx][ky]) {
							res.push_back({kx, ky});
							break;
						}
						kx += i, ky += j;
					}
				}
			}

			return res;
		}

};

int main(void) {
	/* vec2di queens = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
	veci king = {0, 0}; */
	vec2di queens = {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}};
	veci king = {3, 3};

	Solution sol{};
	vec2di selected_queens = sol.queensAttackTheKing_shorter_version(queens, king);

	for (veci q: selected_queens) {
		cout << q[0] << ',' << q[1] << '\n';
	}

	return 0;
}
