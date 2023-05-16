#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using vvec = vector<vector<int>>;
using vec = vector<int>;

bool is_subset_sum(const vec& nums, int idx, int target, vvec& space) {
	if (0 == target) {
		return true;
	} else if (idx == nums.size()) {
		return false;
	}

	if (space[idx][target] != -1) {
		return space[idx][target] == 0 ? false : true;
	}

	bool res{false};
	if (target >= nums[idx]) {
		res = is_subset_sum(nums, idx + 1, target - nums[idx], space);
	}
	res |= is_subset_sum(nums, idx + 1, target, space);

	space[idx][target] = res ? 1 : 0;
	return res;
}

bool is_subset_sum_tabulation(const vec& nums, size_t target) {
	vvec space(nums.size() + 1, vec(target + 1, false));
	for (size_t i = 0; i <= nums.size(); i++) {
		space[i][0] = true;
	}

	for (size_t i = 1; i <= nums.size(); i++) {
		for (size_t j = 1; j <= target; j++) {
			if (nums[i - 1] > target) {
				space[i][j] = space[i - 1][j];
			} else {  // may or may not include this number
				space[i][j] = space[i - 1][j] || space[i - 1][j - nums[i - 1]];
			}
		}
	}

	// get all the subsets
	// mentioned in problem "subset_sum_count.cpp" in this same folder

	return space[nums.size()][target];
}

int main(void) {
	size_t n{};
	cin >> n;

	vec nums(n, 0);
	for (size_t i = 0; i < n; i++) {
		cin >> nums[i];
	}

	size_t sum = accumulate(nums.begin(), nums.end(), 0);
	// vvec space(n + 1, vec((sum / 2) + 1, -1));
	cout << (sum % 2 == 0
			// ? (is_subset_sum(nums, 0, sum / 2, space)
			? (is_subset_sum_tabulation(nums, sum / 2)
				? "true" : "false")
			: "false") << endl;

	return 0;
}
