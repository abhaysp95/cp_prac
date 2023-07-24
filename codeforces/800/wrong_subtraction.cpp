#include <bits/stdc++.h>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	int n = nxt(), k = nxt();

	while (k--) {
		if (n % 10 == 0) n /= 10;
		else n--;
	}

	cout << n << '\n';

	return 0;
}
