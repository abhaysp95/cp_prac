#include <bits/stdc++.h>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	int n = nxt();
	int step = 0;
	step += n / 5;
	n %= 5;
	step += n / 4;
	n %= 4;
	step += n / 3;
	n %= 3;
	step += n / 2;
	n %= 2;
	step += n / 1;
	n %= 1;

	cout << step << '\n';

	return 0;
}
