#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int count = 0, x = 0;
		int maxf = INT_MIN;
		vector<int> vec(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
		}

		for (int d = n; d > 0; d--) {
			count = 0;
			for (int i = 0; i < n; i++) {
				if (d % vec[i] == 0) count++;
			}
			maxf = max(maxf, count);
		}

		cout << maxf << '\n';
	}

	return 0;
}
