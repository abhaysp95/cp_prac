// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>

using namespace std;

void combination_sum(vector<int>& arr, int idx, int target, vector<int>& temp, vector<vector<int>>& res);

int main(void) {
	vector<int> arr = {2, 3, 6, 7};
	int target = 7;

	vector<int> temp{};
	vector<vector<int>> res{};
	combination_sum(arr, 0, target, temp, res);

	for (vector<int>& arr: res) {
		for (int x: arr) {
			cout << x << " ";
		}
		cout << '\n';
	}

	return 0;
}

/* void combination_sum(vector<int>& arr, int idx, int target, int sum, vector<vector<int>>& res) {
	if (target > sum) {
		return;
	}
	if (target == sum) {

	}

	size_t count = 0;
	while (true) {
		if (sum + arr[idx] * count > target) {
			break;
		}
		combination_sum(arr, idx + 1, arr[idx] * count, sum + (arr[idx] * count), res);
		count++;
	}

} */

void combination_sum(vector<int>& arr, int idx, int target, vector<int>& temp, vector<vector<int>>& res) {
	if (0 == target) {
		res.push_back(temp);
		return;
	} else if (0 > target) {
		return;
	}
	if (idx == arr.size()) {  // and target didn't reached
		return;
	}

	combination_sum(arr, idx + 1, target, temp, res);
	temp.push_back(arr[idx]);
	combination_sum(arr, idx, target - arr[idx], temp, res);
	temp.pop_back();
}
