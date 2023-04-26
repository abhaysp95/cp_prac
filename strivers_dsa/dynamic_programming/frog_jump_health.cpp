#include <bits/stdc++.h>

using namespace std;

// idx is 0-index based
int frog_jump_health_recursive(const vector<int>& arr, int idx) {
	if (idx == 0) {
		return 0;
	}

	int left = frog_jump_health_recursive(arr, idx - 1) + (abs(arr[idx] - arr[idx - 1]));
	if (idx > 1) {
		int right = frog_jump_health_recursive(arr, idx - 2) + (abs(arr[idx] - arr[idx - 2]));
		return min(left, right);
	}

	return left;
}

// there is problem overlapping hence memoization of above problem can be done
int frog_jump_health_memoized(const vector<int>& arr, int idx, int *space) {
	if (idx == 0) {
		return 0;
	}

	if (space[idx] != -1) {
		return space[idx];
	}
	int left = frog_jump_health_memoized(arr, idx - 1, space) + abs(arr[idx] - arr[idx -1]);
	if (idx > 1) {  // shouldn't jump two space if it's 1
		int right = frog_jump_health_memoized(arr, idx - 2, space) + abs(arr[idx] - arr[idx - 2]);
		return min(left, right);
	}

	return left;
}

int main(void) {
	vector<int> health = {10, 20, 30, 10};

	// printf("%d\n", frog_jump_health_recursive(health, health.size() - 1));
	int space[health.size()];
	memset(space, -1, sizeof(space));
	printf("%d\n", frog_jump_health_memoized(health, health.size() - 1, space));

	return 0;
}
