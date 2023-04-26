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


int main(void) {
	vector<int> health = {10, 20, 30, 10};

	printf("%d\n", frog_jump_health_recursive(health, health.size() - 1));

	return 0;
}
