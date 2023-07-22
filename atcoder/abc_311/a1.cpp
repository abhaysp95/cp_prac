#include <iostream>

using namespace std;

int32_t main(void) {
	int n;
	cin >> n;
	string s{};
	cin >> s;

	bool a = false, b = false, c = false;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a && b && c) break;
		if (s[i] == 'A') a = true;
		if (s[i] == 'B') b = true;
		if (s[i] == 'C') c = true;
		count++;
	}

	cout << count << '\n';

	return 0;
}
