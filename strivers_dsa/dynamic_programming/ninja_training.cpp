#include <bits/stdc++.h>
#include <climits>
#include <cstring>

using namespace std;

#define DEBUG

int maximum_training_merit_recursive(const vector<vector<int>>& training, int day, int task) {
	// base case
	if (day == 0) {
		int maxi = INT_MIN;
		for (int i = 0; i < 3; i++) {
			if (i != task) {
				maxi = max(maxi, training[0][i]);
			}
		}
#ifdef DEBUG
		printf("%d, %d\n", task, maxi);
#endif
		return maxi;
	}


	int maxi = INT_MIN;
	for (int i = 0; i < 3; i++) {  // task loop
		if (i != task) {
			int res = training[day][i] + maximum_training_merit_recursive(training, day - 1, i);
			maxi = max(maxi, res);
#ifdef DEBUG
			printf("%d, %d, %d\n", task, res, maxi);
#endif
		}
	}
	printf("------------\n");

	return maxi;
}

int space[1000][3];

int maximum_training_merit_memoized(const vector<vector<int>>& training, int day, int task) {
	// base case
	if (day == 0) {
		int maxi = INT_MIN;
		for (int i = 0; i <= 2; i++) {
			if (i != task) {
				maxi = max(maxi, training[0][i]);
			}
		}

		return maxi;
	}

	if (task != 3 && space[day][task] != -1) {  // starting point
		return space[day][task];
	}

	int maxi = INT_MIN;
	for (int i = 0; i <= 2; i++) {
		if (i != task) {
			int res = training[day][i] + maximum_training_merit_memoized(training, day - 1, i);
			maxi = max(maxi, res);
		}
	}

	if (task != 3) {
		space[day][task] = maxi;
	}

	return maxi;
}

// this approach is not exactly based on the recursive solution I wrote above
int maximum_training_merit_tabular(const vector<vector<int>>& training) {
	int space[training.size()][3];
	memset(space, 0, sizeof(space));

	// fill up base day
	for (int i = 0; i < 3; i++) {
		space[0][i] = training[0][i];
	}

	for (int i = 1; i < training.size(); i++) {
		space[i][0] = space[i - 1][0] + max(training[i][1], training[i][2]);
		space[i][1] = space[i - 1][1] + max(training[i][0], training[i][2]);
		space[i][2] = space[i - 1][2] + max(training[i][0], training[i][1]);
	}

	return space[training.size() - 1][2];
}

int main(void) {
	vector<vector<int>> training = { {2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7} }; /* { { 1, 2, 5 }, { 3, 1, 1 }, { 3, 3, 3 } }; */

	// printf("%d\n", maximum_training_merit_recursive(training, training.size() - 1, 3));

	/* memset(space, -1, sizeof(int[3]) * training.size());
	printf("%d\n", maximum_training_merit_memoized(training, training.size() - 1, 3)); */

	printf("%d\n", maximum_training_merit_tabular(training));

	return 0;
}
