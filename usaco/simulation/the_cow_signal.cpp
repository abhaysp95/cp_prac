// wrong

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
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

	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");

	int m = nxt(fin), n = nxt(fin), k = nxt(fin);
	vector<string> res;

	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;

		string amp{};
		for (int c = 0; c < n; c++) {
			amp += string(k, input[c]);
		}
		for (int j = 0; j < k; j++) res.push_back(amp);
	}

	for (const string s: res) {
		fout << s << '\n';
	}

	return 0;
}

/** input:
 * 5 4 2
 * XXX.
 * X..X
 * XXX.
 * X..X
 * XXX.
 */
