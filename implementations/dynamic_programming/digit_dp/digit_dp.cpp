#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("digit_dp.in");
ofstream fout("digit_dp.out");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

// missing 101, when using 'space', why ?
int digit_dp(const vector<int>& num, int d, int k, int idx, int dfreq, bool is_small, vector<int>& store,
		int (*space)[10][2]) {
	if (dfreq > k) return 0;

	if (idx == num.size()) {
		if (dfreq == k) {
			for (const int x: store) cout << x;
			cout << '\n';
			return 1;
		}
		return 0;
	}

	if (space[idx][dfreq][is_small] != -1) {
		return space[idx][dfreq][is_small];
	}

	int limit = 0, res = 0;

	if (is_small) {  // number is already small from b, place any digit here
		limit = 9;
	} else limit = num[idx];

	for (int dgt = 0; dgt <= limit; dgt++) {
		bool nf = is_small;
		if (!is_small && dgt < limit) nf = true;
		store[idx] = dgt;
		res += digit_dp(num, d, k, idx + 1, dgt == d ? dfreq + 1 : dfreq, nf, store, space);
		store[idx] = 0;
	}

	return space[idx][dfreq][is_small] = res;
}

void solve() {
	// a -> range start
	// b -> range end
	// d -> target digit in number
	// k -> required count of d in number
	int a = nxt(fin), b = nxt(fin), d = nxt(fin), k = nxt(fin);

	vector<int> num{};

	while (b > 0) {
		num.push_back(b % 10);
		b /= 10;
	}
	reverse(all(num));
	vector<int> store(num.size());

	int space[10][10][2];
	memset(space, -1, sizeof(space));

	fout << digit_dp(num, d, k, 0, 0, false, store, space) << '\n';
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

