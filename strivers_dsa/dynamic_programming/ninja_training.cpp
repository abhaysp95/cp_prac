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

int main(void) {
	vector<vector<int>> training ={ { 1, 2, 5 }, { 3, 1, 1 }, { 3, 3, 3 } };

	// printf("%d\n", maximum_training_merit_recursive(training, training.size() - 1, 3));

	memset(space, -1, sizeof(int[3]) * training.size());
	printf("%d\n", maximum_training_merit_memoized(training, training.size() - 1, 3));

	return 0;
}
