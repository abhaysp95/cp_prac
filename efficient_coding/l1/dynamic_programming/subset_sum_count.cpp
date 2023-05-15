#include <bits/stdc++.h>

using namespace std;
using vvec = vector<vector<int>>;
using vec = vector<int>;

size_t count_subset_sum(const vector<int>& nums, size_t target, int idx, size_t csum, vvec& space) {
	if (csum == target) {
		return 1;
	} else if (csum > target) {
		return 0;
	} else if (idx == nums.size()) {
		return 0;
	}

	if (space[idx][csum] != -1) {
		return space[idx][csum];
	}

	return space[idx][csum] = count_subset_sum(nums, target, idx + 1, csum, space)
		+ count_subset_sum(nums, target, idx + 1, csum + nums[idx], space);
}

size_t count_subset_sum_tabulation(const vector<int>& nums, size_t target) {
	vvec space(nums.size() + 1, vec(target + 1, 0));
	for (size_t i = 0; i <= nums.size(); i++) {
		space[i][0] = 1;
	}

	for (size_t i = 1; i <= nums.size(); i++) {
		for (size_t j = 1; j <= target; j++) {
			if (nums[i - 1] > j) {  // if number you've is bigger than target, don't include it
				space[i][j] = space[i - 1][j];
			} else {  // else I may or may not include the number
				space[i][j] = space[i - 1][j] + space[i - 1][j - nums[i - 1]];
			}
		}
	}

	return space[nums.size()][target];
}

int main(void) {
	size_t n{};
	cin >> n;

	vector<int> nums(n, 0);
	for (size_t i = 0; i < n; i++) {
		cin >> nums[i];
	}

	size_t target{};
	cin >> target;

	/* vvec space(n, vec(target, -1));
	cout << count_subset_sum(nums, target, 0, 0, space) << endl; */

	/* for (vec& v: space) {
		for (int x: v) {
			cout << x << " ";
		}
		cout << endl;
	} */

	cout << count_subset_sum_tabulation(nums, target) << endl;

	return 0;
}

/** inputs:
 * n
 * num array
 * target
 *
 * 6
 * 2 3 5 6 8 10
 * 10
 * *********************
 * 7
 * 1 2 3 5 6 8 10
 * 10
 * *********************
 * 4
 * 2 3 5 6
 * 5
 */
