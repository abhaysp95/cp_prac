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

int house_robber_tabular(const vector<int>& nums) {
	int space[nums.size()];  // cause we'll leave 1 house (in each case)

	// leave the right-most house
	space[0] = 0;
	space[1] = nums[0];
	for (size_t i = 2; i < nums.size(); i++) {
		space[i] = max(space[i - 1], space[i - 2] + nums[i - 1]);
	}
	int left = space[nums.size() - 1];

	// leave the left-most house
	space[0] = 0;
	space[1] = nums[1];
	for (size_t i = 2; i < nums.size(); i++) {
		space[i] = max(space[i - 1], space[i - 2] + nums[i]);
	}
	int right = space[nums.size() - 1];

	printf("%d, %d\n", left, right);

	return max(left, right);
}

// first house is adjacent of last house (circular structure)
int house_robber_solution(const vector<int>& nums) {
	if (nums.size() == 1) return nums[0];

	int space[nums.size() + 1];
	memset(space, -1, sizeof(space));
	int left = house_robber_memoized(nums, 0, nums.size() - 1, space);  // leaving last house
	memset(space, -1, sizeof(space));
	int right = house_robber_memoized(nums, 1, nums.size(), space);  // leaving first house

	return max(left, right);
}

// NOTE: the easiest thing to do would be to make 2 different arrays, leaving
// one house from each end in each of the arrays respectively and then use the
// same algo we used in "max sum of non adjacent" algo. I used the same algo
// here, but I didn't made two different arrays, which made it slightly
// difficult

int main(void) {
	vector<int> vec = { 200, 3, 140, 20, 10 }; /* { 1, 2, 3, 1 }; */ /* { 2, 3, 2 }; */

	printf("%d\n", house_robber_tabular(vec));

	return 0;
}
