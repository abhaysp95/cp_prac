#include <bits/stdc++.h>

using namespace std;

size_t ways_to_climb_stairs(int N) {
	if (N == 0) {
		return 1;
	}

	size_t sum = ways_to_climb_stairs(N - 1);
	if (N > 1) {
		sum += ways_to_climb_stairs(N - 2);
	}

	return sum;
}


size_t ways_to_climb_stairs_tabulation(size_t N) {
	vector<int> space(N + 1, 0);
	space[0] = 1;

	for (int i = 1; i <= N; i++) {
		space[i] = space[i - 1] + (i > 1 ? space[i - 2] : 0);
	}

	return space[N];
}

size_t ways_to_climb_stairs_tabulation_space_optimized(size_t N) {
	vector<int> space(2, 1);
	space[0] = 1;

	for (int i = 2; i <= N; i++) {
		size_t res = space[1] + space[0];
		space[0] = space[1];
		space[1] = res;
		// space[i] = space[i - 1] + (i > 1 ? space[i - 2] : 0);
	}

	return space[1];
}

int main(void) {
	size_t N{};
	cin >> N;

	// cout << ways_to_climb_stairs(N) << endl;
	cout << ways_to_climb_stairs_tabulation_space_optimized(N) << endl;

	return 0;
}
