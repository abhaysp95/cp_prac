#include <bits/stdc++.h>
#include <cstdio>

#define DEBUG 1

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

int frog_jump_health_tabular(const vector<int>& health) {
	int arr[health.size()];

	// base
	arr[0] = 0;
	arr[1] = abs(health[1] - health[0]);

	for (size_t i = 2; i < health.size(); i++) {  // 0-based idx (hence, run upto size - 1
		arr[i] = min(arr[i - 1] + abs(health[i] - health[i - 1]),
				arr[i - 2] + abs(health[i] - health[i - 2]));
	}

#ifdef DEBUG
	for (size_t i = 0; i < health.size(); i++) {
		printf("%d ", arr[i]);
	}
	fputs("\n", stdout);
#endif

	return arr[health.size() - 1];
}

int main(void) {
	vector<int> health = {30, 10, 60, 10, 60, 50};  // {10, 20, 30, 10};

	// printf("%d\n", frog_jump_health_recursive(health, health.size() - 1));

	/* int space[health.size()];
	memset(space, -1, sizeof(space));
	printf("%d\n", frog_jump_health_memoized(health, health.size() - 1, space)); */

	printf("%d\n", frog_jump_health_tabular(health));

	return 0;
}
