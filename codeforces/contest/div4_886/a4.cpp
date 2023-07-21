#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		int n, x;
		cin >> n >> x;
		vector<int> vec(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
		}

		sort(vec.begin(), vec.end());

		if (vec.size() == 1) {
			cout << 0 << '\n';
			continue;
		}

		int prev = 0;
		int maxs = INT_MIN;
		for (int i = 1; i < n; i++) {
			if (vec[i] - vec[i - 1] > x) {
				maxs = max(maxs, i - prev);
				prev = i;
			}
		}
		maxs = max(maxs, n - prev);

		cout << n - maxs << '\n';
	}

	return 0;
}
