// variant: each job takes 1 - unit of time
// input: <job id, deadline, profit>

#include <bits/stdc++.h>
#include <cstring>

#define SZ 8

using namespace std;

int max_profit(vector<vector<int>>& jobs) {
	int maxp{};

	int max_deadline{};
	sort(jobs.begin(), jobs.end(), [&](vector<int> x, vector<int>& y) {
			max_deadline = max(max_deadline, max(x[1], y[1]));
			return x[2] > y[2];
			});

	int profits[max_deadline];
	memset(profits, -1, SZ * sizeof(int));

	for (size_t i{}; i < SZ; i++) {
		const vector<int>& job = jobs[i];
		printf("(%d, %d, %d)\n", job[0], job[1], job[2]);
	}

	for (size_t i{}; i < SZ; i++) {
		vector<int>& curr_job = jobs[i];
		int deadline = curr_job[1];
		if (-1 == profits[deadline - 1]) {  // job id is 1 indexed not 0
			profits[deadline - 1] = curr_job[0];
			maxp += curr_job[2];
		} else {  // there's already job for the deadline
			// traverse to find anything before it
			for (int j = deadline - 1; j >= 0; j--) {
				if (-1 == profits[j]) {
					profits[j] = curr_job[0];
					maxp += curr_job[2];
					break;
				}
			}
		}
	}

	// print job-ids used
	for (size_t i{}; i < max_deadline; i++) {
		printf("%d ", profits[i]);
	}
	putchar('\n');

	return maxp;
}

int main(void) {

	vector<vector<int>> jobs = {{1, 4, 20}, {2, 5, 60}, {3, 6, 70}, {4, 6, 65}, {5, 4, 25}, {6, 2, 80}, {7, 2, 10}, {8, 2, 22}};

	printf("%d\n", max_profit(jobs));

	return 0;
}
