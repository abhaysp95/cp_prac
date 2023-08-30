#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	int n = 5;
	vector<int> nums = {10, 5, 20, 40, 1};
	vector<int> diff (n + 2, 0);

	int updateValue = 10;
	vector<pair<int, int>> q = {{0, 2}, {2, 5}};

	for (int i = 0; i < q.size(); i++) {
		int l = q[i].first, r = q[i].second;
		diff[l] += updateValue;
		diff[r + 1] -= updateValue;
	}

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
		nums[i - 1] += diff[i];
	}

	for (int i = 0; i < n; i++) cout << nums[i] << " ";
	cout << endl;

	return 0;
}

// https://codeforces.com/blog/entry/78762
