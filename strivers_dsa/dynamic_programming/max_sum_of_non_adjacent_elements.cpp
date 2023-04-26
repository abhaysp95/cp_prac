#include <bits/stdc++.h>

using namespace std;

// inclusive idx
int max_sum_non_adj_recursive(const vector<int>& arr, int idx) {
	if (idx == 0) { // this call is redundant but saves the one level function call each time idx == 0
		return arr[idx];
	}
	if (idx < 0) {
		return 0;
	}

	int no_pick = max_sum_non_adj_recursive(arr, idx - 1);
	int pick = max_sum_non_adj_recursive(arr, idx - 2) + arr[idx];

	return max(no_pick, pick);
}

int max_sum_non_adj_memoized(const vector<int>& arr, int idx, int *space) {
	if (idx == 0) {
		return arr[idx];
	}
	if (idx < 0) {
		return 0;
	}

	if (-1 != space[idx]) {
		return space[idx];
	}

	space[idx] = max(max_sum_non_adj_memoized(arr, idx - 1, space),
			arr[idx] + max_sum_non_adj_memoized(arr, idx - 2, space));
	return space[idx];
}

int max_sum_non_adj_tabular(const vector<int>& arr) {
	int space[arr.size() + 1];
	memset(space, -1, sizeof(space));

	space[0] = 0;
	space[1] = arr[0];

	for (size_t i = 2; i <= arr.size(); i++) {
		space[i] = max(space[i - 1], space[i - 2] + arr[i - 1]);  // arr is moving 1 behind space
	}

	return space[arr.size()];
}

int main(void) {
	vector<int> arr = {2, 1, 4, 9};

	// printf("%d\n", max_sum_non_adj_recursive(arr, arr.size() - 1));

	/* int space[arr.size()];
	memset(space, -1, sizeof(space));
	printf("%d\n", max_sum_non_adj_memoized(arr, arr.size() - 1, space)); */

	printf("%d\n", max_sum_non_adj_tabular(arr));

	return 0;
}
