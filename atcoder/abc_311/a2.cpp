#include <bits/stdc++.h>

using namespace std;

int32_t main(void) {
	int n, d;
	cin >> n >> d;

	vector<bool> darr(d, true);

	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> c;
			if (c == 'o') darr[j] = darr[j] & true;
			if (c == 'x') darr[j] = darr[j] & false;
		}
	}

	int count = 0, prev = 0, cur = 0;
	int maxc = 0;
	for (; cur < d; cur++) {
		if (!darr[cur]) {
			maxc = max(maxc, cur - prev);
			prev = cur + 1;
		}
	}

	maxc = max(maxc, cur - prev);
	cout << maxc << '\n';

	return 0;
}
