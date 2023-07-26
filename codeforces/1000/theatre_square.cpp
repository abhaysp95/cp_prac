#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(a) (int)(a.size())

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	int n = nxt(), m = nxt(), a = nxt();
	long long h = 0, b = 0;
	h += n / a;
	h += (n % a ? 1 : 0);
	b += m / a;
	b += (m % a ? 1 : 0);

	cout << h * b << '\n';
}
