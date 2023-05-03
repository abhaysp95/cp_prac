#include <bits/stdc++.h>
#include <cstdio>

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

// update the array by removing duplicates and also give the new length
void remove_duplicates(void) {
	vector<int> nums = {1, 1, 2, 2, 2, 3, 3};

	if (nums.empty() || nums.size() == 1) {
		// return this lenght
		printf("updated len: %zu\n", nums.size());
		return;
	}

	size_t i{1}, j{1};
	for (; i < nums.size(); i++) {
		// if duplicate found
		if (i != j && nums[i] != nums[j]) {
			if (nums[i] == nums[i - 1]) {
				nums[j] = nums[i];
				j++;
			}
		}
	}

	printf("updated len: %zu\n", j);

	// print this new array
	for (size_t x{}; x < j; x++) {
		printf("%d ", nums[x]);
	}
	puts("\n");
}

// better in coding only, complexity is similar
void remove_duplicates_better(void) {
	vector<int> nums = {1, 1, 2, 2, 2, 3, 3};

	size_t i = 1, j = 0;
	for (; i < nums.size(); i++) {
		if (nums[i] != nums[j]) {  // unique
			nums[++j] = nums[i];
		}
	}
	j++; // shows new size

	printf("updated len: %zu\n", j);

	// print this new array
	for (size_t x{}; x < j; x++) {
		printf("%d ", nums[x]);
	}
	puts("\n");
}

int main(void) {
	two_sum();
	remove_duplicates_better();
}
