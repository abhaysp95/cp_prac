// wrong

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <fstream>

using namespace std;

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cerr.tie(nullptr);

	ifstream fin("lostcow.in");
	ofstream fout("lostcow.out");

	// x & y are +ve or 0
	int x = nxt(fin), y = nxt(fin);
	int prev = 3, cur = 3;
	int dir = true, d = 0;
	int td = 0;
	while (true) {
		if (cur == y) break;
		prev = cur;
		if (dir) {
			cur = x + (int)pow(2, d);
		} else cur = abs(x - (int)pow(2, d));
		d++;
		dir = !dir;
		cur = min(cur, y);
		td += abs(cur - prev);
	}

	fout << td << '\n';

	return 0;
}

/** input:
 * 3 6
 * */
