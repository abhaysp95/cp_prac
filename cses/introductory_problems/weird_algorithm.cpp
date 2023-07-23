#include <bits/stdc++.h>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

// no benefit (cause I'm not seeing repitition), though I'm not sure
/* unordered_map<int, vector<int>> umap{};

vector<int> weird(int n) {
	if (n == 1) return vector<int>{1};

	if (umap.find(n) != umap.end()) return umap[n];

	vector<int> val{};
	if (n & 1) {
		val = weird(n * 3 + 1);
	} else {
		val = weird(n / 2);
	}

	umap[n].insert(umap[n].end(), val.begin(), val.end());

	return val;
} */


// giving TLE and wrong ans in some cases (will visit back)
int32_t main(void) {
	vector<int> space(1e7);
	int n = nxt();
	while (n != 1) {
		cout << n << " ";
		if (n & 1) {
			n *= 3;
			n++;
		} else n /= 2;
	}
	// weird(n);
	cout << 1 << '\n';

	return 0;
}
