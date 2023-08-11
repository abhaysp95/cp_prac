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

class Solution {
	int drow[4] = {-1, 0, 1, 0};
	int dcol[4] = {0, -1, 0, 1};
	public:
		int maximumSafenessFactor(vector<vector<int>>& grid) {
			int n = sz(grid);
			queue<pair<pair<int, int>, int>> q{};
			auto sfd = initv2d(n, n, INT_MAX);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j]) {
						q.push({{i, j}, 0});
						sfd[i][j] = 0;
					}
				}
			}

			int start = 0, end = 0;
			while (!q.empty()) {
				auto p = q.front();
				q.pop();
				int x = p.first.first, y = p.first.second, d = p.second;
				end = max(end, d);
				for (int k = 0; k < 4; k++) {
					int nx = x + drow[k], ny = y + dcol[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && d + 1 < sfd[nx][ny]) {
						q.push({{nx, ny}, d + 1});
						sfd[nx][ny] = d + 1;
					}
				}
			}

			int ans = 0;
			while (start <= end) {
				int mid = (start + end) / 2;
				int res = safeness_factor(sfd, mid);
				if (res) {
					ans = mid;
					start = mid + 1;
				} else end = mid - 1;
			}

			return ans;
		}

		int safeness_factor(const vector<vector<int>>& sfd, int mid) {
			if (sfd[0][0] < mid) return false;

			int n = sz(sfd);
			auto visited = initv2d(n, n, false);
			queue<pair<int, int>> q{};
			q.push({0, 0});
			visited[0][0] = true;

			while (!q.empty()) {
				auto p = q.front();
				q.pop();
				int x = p.first, y = p.second;

				if (x == n - 1 && y == n - 1) return true;

				for (int k = 0; k < 4; k++) {
					int nx = x + drow[k], ny = y + dcol[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && sfd[nx][ny] >= mid && !visited[nx][ny]) {
						visited[nx][ny] = true;
						q.push({nx, ny});
					}
				}
			}

			return false;
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

