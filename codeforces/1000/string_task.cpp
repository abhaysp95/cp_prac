#include <bits/stdc++.h>
#include <cctype>

using namespace std;

#define ll long long
#define sz(a) (int)(a.size())

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

bool isvowel(char c) {
	return c == 'A' ||
		c == 'E' ||
		c == 'I' ||
		c == 'O' ||
		c == 'U' ||
		c == 'Y' ||
		c == 'a' ||
		c == 'e' ||
		c == 'i' ||
		c == 'o' ||
		c == 'u' ||
		c == 'y';
}

int32_t main(void) {
	string str;
	cin >> str;

	string res;
	for (char c: str) {
		if (!isvowel(c)) {
			res += '.';
			res += isupper(c) ? tolower(c) : c;
		}
	}

	cout << res << '\n';

	return 0;
}
