#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> vec(n, pair<int, int>{});

		for (int i = 0; i < n; i++) {
			cin >> vec[i].first;
			cin >> vec[i].second;
		}

		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (vec[i].first == vec[j].first || vec[i].second == vec[j].second) count += 2;
				else {
					int a = abs(vec[i].first - vec[j].first);
					int l = abs(vec[i].second - vec[j].second);
					if (a == l) count += 2;
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}
