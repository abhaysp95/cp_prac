#include <bits/stdc++.h>

using namespace std;

int32_t main(void) {
	int n;
	cin >> n;
	string str;
	cin >> str;

	int ans = 0;
	for (int i = 0; i + 1 < str.size(); i++) {
		if (str[i] == str[i + 1]) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
