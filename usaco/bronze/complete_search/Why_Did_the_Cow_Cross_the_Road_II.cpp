#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("circlecross.in");
ofstream fout("circlecross.out");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}


// traverse for each cow (keep record of which cow you traversed for)
// look if before you finish exit for the cow you started, there's entry for another cow, but you haven't hit exit
// this will make for a pair
// problem is, if A & B makes a pair, so does B & A. So, when check for B, you'll have to rule out A from getting in record again
// maybe, make a 2d array 26x26 and say for B & A, check in A's array if there already exists B. If yes, don't include it in count
void solve() {
	string input{};
	fin >> input;

	int done[26];
	memset(done, 0, sizeof(done));
	int record[26][26];
	memset(record, 0, sizeof(record));

	int count = 0;
	for (int i = 0; i < input.size(); i++) {
		if (done[input[i] - 'A']) continue;
		done[input[i] - 'A'] = 1;

		for (int j = i + 1; j < input.size(); j++) {
			if (input[j] == input[i]) break;

			int &val = record[input[i] - 'A'][input[j] - 'A'];
			val = val ? 0 : 1;  // if met already, then this is the end, else this is start
		}

		for (int j = 0; j < 26; j++) {
			if (record[input[i] - 'A'][j] && !record[j][input[i] - 'A']) count++;
		}
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

