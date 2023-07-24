#include <bits/stdc++.h>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	int s = nxt(), b = nxt();
	int count = 0;
	while (s <= b) {
		s *= 3;
		b *= 2;
		count++;
	}

	cout << count << '\n';

	return 0;
}
