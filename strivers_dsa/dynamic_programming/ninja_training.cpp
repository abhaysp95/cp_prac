#include <bits/stdc++.h>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

#define DEBUG

int maximum_training_merit_recursive(const vector<vector<int>>& training, int day, int last) {
	// base case
	if (day == 0) {
		int maxi = INT_MIN;
		for (int task = 0; task < 3; task++) {
			if (task != last) {
				maxi = max(maxi, training[0][task]);
			}
		}
#ifdef DEBUG
		printf("%d, %d\n", last, maxi);
#endif
		return maxi;
	}


	int maxi = INT_MIN;
	for (int task = 0; task < 3; task++) {  // task loop
		if (task != last) {
			int res = training[day][task] + maximum_training_merit_recursive(training, day - 1, task);
			maxi = max(maxi, res);
#ifdef DEBUG
			printf("%d, %d, %d\n", last, res, maxi);
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
	// row: day count
	// column: same task you performed on last day + max(today you perform the other 2 tasks)
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

// following appraoch is based on the recursive solution wrote above
int maximum_training_merit_tabular_second(const vector<vector<int>>& training) {
	// row: day count
	// column: stores the data on what I performed last
	int space[training.size()][4];  // apparently, tasks are 0, 1, 2 & 3 (meaning we don't know)
	memset(space, -1, sizeof(space));

	// base case
	space[0][0] = max(training[0][1], training[0][2]);
	space[0][1] = max(training[0][0], training[0][2]);
	space[0][2] = max(training[0][0], training[0][1]);
	space[0][3] = max(training[0][0], max(training[0][1], training[0][2]));

	for (int i = 1; i < training.size(); i++) {
		for (int last = 0; last <= 3; last++) {  // last task done
			for (int task = 0; task <= 2; task++) {
				if (task != last) {
					int merit = training[i][task] + space[i - 1][task];
					space[i][last] = max(space[i][last], merit);
				}
			}
		}
	}

	return space[training.size() - 1][3];
}

// same as above but space optimized
int maximum_training_merit_tabular_second_space_optimized(const vector<vector<int>>& training) {
	int space[2][4];  // the second row is just for temp space (result is only stored in row 0 every time)
	memset(space, -1, sizeof(space));

	// base case
	space[0][0] = max(training[0][1], training[0][2]);
	space[0][1] = max(training[0][0], training[0][2]);
	space[0][2] = max(training[0][0], training[0][1]);
	space[0][3] = max(training[0][0], max(training[0][1], training[0][2]));

	for (int day = 1; day < training.size(); day++) {
		for (int last = 0; last <= 3; last++) {
			for (int task = 0; task <=2; task++) {
				if (last != task) {
					int merit = training[day][task] + space[0][task];
					space[1][last] = max(space[1][last], merit);
				}
			}
		}
		// re-organize the space
		for (int i = 0; i <= 3; i++) {
			space[0][i] = space[1][i];
			space[1][i] = -1;
		}
	}

	return space[0][3];
}

int main(void) {
	vector<vector<int>> training = { {2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7} }; /* { { 1, 2, 5 }, { 3, 1, 1 }, { 3, 3, 3 } }; */

	// printf("%d\n", maximum_training_merit_recursive(training, training.size() - 1, 3));

	/* memset(space, -1, sizeof(int[3]) * training.size());
	printf("%d\n", maximum_training_merit_memoized(training, training.size() - 1, 3)); */

	printf("%d\n", maximum_training_merit_tabular_second_space_optimized(training));

	return 0;
}
