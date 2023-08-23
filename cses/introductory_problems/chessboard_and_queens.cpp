#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

bool check(const vector<string>& board, int r , int c) {
	for (int i = 0; i < 8; i++) {
		if (board[r][i] == 'q' && i != c) return false;
	}
	for (int i = 0; i < 8; i++) {
		if (board[i][c] == 'q' && i != r) return false;
	}

	for (int i = r - 1; i >= 0; i--) {
		if (c + (r - i) < 8  && board[i][c + (r - i)] == 'q') return false;
		if (c - (r - i) >= 0  && board[i][c - (r - i)] == 'q') return false;
	}

	for (int i = r + 1; i < 8; i++) {
		if (c + (i - r) < 8 && board[i][c + (i - r)] == 'q') return false;
		if (c - (i - r) >= 0 && board[i][c - (i - r)] == 'q') return false;
	}

	return true;
}

int fill_board(vector<string>& board, int r) {
	if (r == 8) {
		/* for (const string& s: board) {
			cout << s << '\n';
		}
		cout << "--------------------\n"; */
		return 1;
	}

	int res = 0;
	for (int c = 0; c < 8; c++) {
		if (board[r][c] != '*' && check(board, r, c)) {
			board[r][c] = 'q';
			res += fill_board(board, r + 1);
			board[r][c] = '.';
		}
	}

	return res;
}

void solve() {
	// vector<string> board(8, string(8, '.'));
	vector<string> board(8);
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> board[i];
	}

	cout << fill_board(board, 0) << '\n';
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cerr.tie(nullptr);

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

