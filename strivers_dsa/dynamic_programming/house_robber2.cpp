#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int house_robber_memoized(const vector<int>& arr, int start, int idx, int *space) {
	if (idx - 1 < start) {
		return 0;
	}

	if (space[idx] != -1) {
		return space[idx];
	}
	int not_pick = house_robber_memoized(arr, start, idx - 1, space);
	int pick = house_robber_memoized(arr, start, idx - 2, space) + arr[idx - 1];  // idx is working on 0 + 1 basis

	return space[idx] = max(not_pick, pick);  // returns space[idx] after assignment
}

// first house is adjacent of last house (circular structure)
int house_robber_solution(const vector<int>& nums) {
	if (nums.size() == 1) return nums[0];

	int space[nums.size() + 1];
	memset(space, -1, sizeof(space));
	int left = house_robber_memoized(nums, 0, nums.size() - 1, space);  // leaving last house
	memset(space, -1, sizeof(space));
	int right = house_robber_memoized(nums, 1, nums.size(), space);  // leaving first house

	// printf("%d, %d", left, right);

	return max(left, right);
}

int main(void) {
	vector<int> vec = { 200, 3, 140, 20, 10 }; /* { 1, 2, 3, 1 }; */ /* { 2, 3, 2 }; */

	printf("%d\n", house_robber_solution(vec));

	return 0;
}
