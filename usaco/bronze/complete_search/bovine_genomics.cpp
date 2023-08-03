#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

/* template <typename T>
inline T nxt(istream& cin = std::cin, T t = 0) {
	T x;
	cin >> x;
	return x;
} */

void solve() {
	int N, M;
	fin >> N >> M;
	vector<string> temp(N * 2);

	for (int i = 0; i < N * 2; i++) {
		fin >> temp[i];
	}

	vector<string> gdata(M, string(N * 2, '\0'));
	for (int i = 0, x = 0; i < N * 2 && x < N * 2; i++, x++) {
		for (int j = 0, y = 0; j < M && y < M; j++, y++) {
			gdata[y][x] = temp[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < M; i++) {
		bool touched[26] = { false };
		for (int j = 0; j < N; j++) {
			touched[gdata[i][j] - 'A'] = true;
		}

		bool unique = true;
		for (int j = 0; j < N; j++) {
			if (touched[gdata[i][j + N] - 'A']) {
				unique = false;
				break;
			}
		}
		if (unique) count++;
	}

	fout << count << '\n';
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

