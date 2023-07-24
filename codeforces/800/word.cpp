#include <bits/stdc++.h>
#include <cctype>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	string str;
	cin >> str;

	int low = 0, up = 0;
	for (const char c: str) {
		if (islower(c)) low++;
		if (isupper(c)) up++;
	}

	if (low >= up) {
		for (char& c: str) c = tolower(c);
	} else {
		for (char& c: str) c = toupper(c);
	}

	cout << str << '\n';

	return 0;
}
