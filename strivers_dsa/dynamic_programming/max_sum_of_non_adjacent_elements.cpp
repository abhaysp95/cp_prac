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

int main(void) {
	vector<int> arr = {2, 1, 4, 9};

	printf("%d\n", max_sum_non_adj_recursive(arr, arr.size() - 1));

	return 0;
}
