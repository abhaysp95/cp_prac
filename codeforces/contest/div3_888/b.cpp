#include <bits/stdc++.h>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> odd{}, even{}, nums(n);
	for (int i = 0; i < n; i++) {
		int x = nxt();
		if (x & 1) odd.push_back(x), nums[i] = 1;
		else even.push_back(x), nums[i] = 2;
	}

	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());

	int o = 0, e = 0, i = 0;
	while (o < odd.size() && e < even.size()) {
		if (nums[i] & 1) nums[i] = odd[o++];
		else nums[i] = even[e++];
		i++;
	}
	while (o < odd.size()) nums[i++] = odd[o++];
	while (e < even.size()) nums[i++] = even[e++];

	bool status = true;
	for (int i = 0; i < n - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			status = false;
			break;
		}
	}

	cout << (status ? "YES" : "NO") << '\n';
}

/* void solve() {
	int n = nxt();
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		nums[i] = nxt();
	}

	for (int i = 0; i < n; i++) {
		if (nums[i] & 1) {
			int mnum = INT_MAX, midx = -1;
			for (int j = i + 1; j < n; j++) {
				if (nums[j] & 1 && nums[i] > nums[j] && mnum > nums[j]) {
					mnum = nums[j], midx = j;
				}
			}
			if (midx != -1) swap(nums[i], nums[midx]);
		} else {
			int mnum = INT_MAX, midx = -1;
			for (int j = i + 1; j < n; j++) {
				if ((nums[j] & 1) == 0 && nums[i] > nums[j] && mnum > nums[j]) {
					mnum = nums[j], midx = j;
				}
			}
			if (midx != -1) swap(nums[i], nums[midx]);
		}
	}

	bool status = true;
	for (int i = 0; i < n - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			status = false;
			break;
		}
	}

	cout << (status ? "YES" : "NO") << '\n';
} */

int32_t main(void) {
	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}
