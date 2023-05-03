#include <bits/stdc++.h>

using namespace std;

// sorted array, find out indices of a pair where pair sums upto target
void two_sum(void) {
	vector<int> nums = {1, 3, 5, 8, 9, 10, 12};
	int target = 14;

	int x = 0;
	int y = nums.size() - 1;

	while (x < y) {
		int sum = nums[x] + nums[y];
		if (sum == target) {
			break;
		} else if (sum < target) {
			x++;
		} else y--;
	}

	printf("two sum: (%d, %d)\n", x, y);
}

int main(void) {
	two_sum();
}
