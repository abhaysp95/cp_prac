#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("billboard.in");
ofstream fout("billboard.out");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

struct rectangle {
	int x1, y1, x2, y2;
	int area() {
		return (x2 - x1) * (y2 - y1);
	}
};

void solve() {
	rectangle a = {
		.x1 = nxt(fin), .y1 = nxt(fin), .x2 = nxt(fin), .y2 = nxt(fin)
	};
	rectangle b = {
		.x1 = nxt(fin), .y1 = nxt(fin), .x2 = nxt(fin), .y2 = nxt(fin)
	};
	rectangle t = {
		.x1 = nxt(fin), .y1 = nxt(fin), .x2 = nxt(fin), .y2 = nxt(fin)
	};

	int aintsec = max((min(a.x2, t.x2) - max(a.x1, t.x1)), 0) * max((min(a.y2, t.y2) - max(a.y1, t.y1)), 0);
	int bintsec = max((min(b.x2, t.x2) - max(b.x1, t.x1)), 0) * max((min(b.y2, t.y2) - max(b.y1, t.y1)), 0);

	// fout << a.area() << ", " << b.area() << ", " << aintsec << ", " << bintsec << '\n';

	fout << a.area() + b.area() - aintsec - bintsec << '\n';
}

/* void solve() {
	int ax1 = nxt(fin), ay1 = nxt(fin), ax2 = nxt(fin), ay2 = nxt(fin);
	int bx1 = nxt(fin), by1 = nxt(fin), bx2 = nxt(fin), by2 = nxt(fin);
	int tx1 = nxt(fin), ty1 = nxt(fin), tx2 = nxt(fin), ty2 = nxt(fin);

	int count = 0;

	for (int i = -1000; i <= 1000; i++) {
		for (int j = -1000; j <= 1000; j++) {
			if (((i >= ax1 && i < ax2 && j >= ay1 && j < ay2)
						|| (i >= bx1 && i < bx2 && j >= by1 && j < by2))
				&& (i < tx1 || i >= tx2 || j < ty1 || j >= ty2)) count++;
		}
	}

	fout << count << '\n';
} */


/* const int MAX_COUNT = 2000;
array<array<bool, MAX_COUNT + 1>, MAX_COUNT + 1> space;

void solve() {
	for (int i = 0; i < 3; i++) {
		int x1 = nxt(fin), y1 = nxt(fin), x2 = nxt(fin), y2 = nxt(fin);
		// make co-ords +ve
		x1 += MAX_COUNT / 2;
		y1 += MAX_COUNT / 2;
		x2 += MAX_COUNT / 2;
		y2 += MAX_COUNT / 2;

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				space[x][y] = i != 2;
			}
		}
	}

	int count = 0;
	for (int i = 0; i <= MAX_COUNT; i++) {
		for (int j = 0; j <= MAX_COUNT; j++) {
			if (space[i][j]) count++;
		}
	}

	fout << count << '\n';
} */

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

