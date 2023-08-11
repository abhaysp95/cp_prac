#include <bits/stdc++.h>
#include <climits>

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

template <typename T>
auto initv2d(int n, int m, T x) {
	return vector<vector<T>>(n, vector<T>(m, x));
}

class SolutionTLED {
	int drow[4] = {-1, 0, 1, 0};
	int dcol[4] = {0, -1, 0, 1};
	public:

		// initial approach
		int maximumSafenessFactor(vector<vector<int>>& grid) {
			int n = sz(grid);
			auto sfd = initv2d(n, n, INT_MAX);
			vector<pair<int, int>> theifs{};

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j]) theifs.push_back({i, j});
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (const pair<int, int>& p: theifs) {
						grid[i][j] = min(grid[i][j], abs(i - p.first) + abs(j - p.second));
					}
				}
			}

			auto visited = initv2d(n, n, false);
			if (sfd[0][0] == 0 || sfd[n - 1][n - 1] == 0) return 0;
			int res = safeness_factor(sfd, n, visited, 0, 0, INT_MAX);

			return res == INT_MIN ? 0 : res;
		}

		int safeness_factor(const vector<vector<int>>& sfd, int n, vector<vector<bool>>& visited, int i, int j, int mind) {
			if (i == n - 1 && j == n - 1) {
				// if (sfd[i][j] == 0) return INT_MIN;
				return min(mind, sfd[i][j]);
			}

			int res = INT_MIN;
			for (int k = 0; k < 4; k++) {
				int x = i + drow[k], y = j + dcol[k];
				if (x >= 0 && x < n && y >= 0 && y < n && sfd[x][y] != 0 && !visited[x][y]) {
					visited[x][y] = true;
					res = max(res, safeness_factor(sfd, n, visited, x, y, min(mind, sfd[x][y])));
					visited[x][y] = false;
				}
			}

			return res;
		}
};

void solve() {

}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cerr.tie(nullptr);

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

