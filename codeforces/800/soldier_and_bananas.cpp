#include <bits/stdc++.h>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	int k = nxt(), n = nxt(), w = nxt();

	int tsum = (w * (k + w * k)) / 2;

	cout << (tsum > n ? tsum - n : 0) << '\n';

	return 0;
}
