#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		vector<pair<pair<int, int>, int>> vec{};
		int n;
		cin >> n;
		int i = 1;
		while (n--) {
			int x, y;
			cin >> x >> y;
			vec.push_back({{x, y}, i});
			i++;
		}

		sort(vec.begin(), vec.end(), [&](pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2) {
					return p1.first.second > p2.first.second;
				});

		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].first.first <= 10) {
				cout << vec[i].second << '\n';
				break;
			}
		}
	}

	return 0;
}
