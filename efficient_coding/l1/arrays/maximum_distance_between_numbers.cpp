#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using umap = unordered_map<int, vector<size_t>>;

int main(void) {
	size_t n{};
	cin >> n;

	// vector<int> arr(n, 0);
	umap num_pos{};
	for (size_t i = 0; i < n; i++) {
		int num;
		cin >> num;
		num_pos[num].push_back(i);
	}

	size_t max_dist{0};
	/* for (size_t i = 0; i < num_pos.size(); i++) {
		size_t dist{};
		if (num_pos[i].size() > 1) {
			dist = num_pos[i].at(num_pos[i].size() - 1) - num_pos[i].at(0);
		} else {
			dist = num_pos[i].at(0);  // problematic line
		}
		max_dist = max(max_dist, dist);
	} */

	for (const pair<const int, vector<size_t>>& p: num_pos) {
		size_t dist{};
		if (p.second.size() > 1) {
			dist = p.second.at(p.second.size() - 1) - p.second.at(0);
		} else {
			dist = p.second.at(0);
		}

		max_dist = max(max_dist, dist);
	}

	cout << "max distance: " << max_dist << endl;

	return 0;
}
