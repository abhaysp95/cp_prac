#include <bits/stdc++.h>

using namespace std;

#define int long long

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	int n = nxt();
	int sum = 0;
	int asum = (n * (1 + n)) / 2;
	while (n != 1) {
		sum += nxt();
		n--;
	}

	cout << asum - sum << '\n';

	return 0;
}
