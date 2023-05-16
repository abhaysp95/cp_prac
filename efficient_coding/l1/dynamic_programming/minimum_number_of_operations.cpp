#include <bits/stdc++.h>
#include <climits>

using namespace std;
using vec = vector<int>;

size_t minimum_operations(size_t num, vec& space) {
	if (num == 0) {
		return 0;
	}

	if (space[num] != -1) {
		return space[num];
	}

	size_t res1{INT_MAX}, res2{INT_MAX};
	if (num % 2 == 0) {
		res1 = minimum_operations(num / 2, space);
	}
	res2 = minimum_operations(num - 1, space);

	return space[num] = min(res1, res2) + 1;
}

size_t minimum_operations_tabulation(size_t num) {
	vec space(num + 1, 0);

	for (size_t i = 1; i <= num; i++) {
		size_t res1{INT_MAX}, res2{INT_MAX};
		if (i % 2 == 0) {
			res1 = space[i / 2];
		}
		res2 = space[i - 1];
		space[i] = 1 + min(res1, res2);
	}

	return space[num];
}

int main(void) {
	size_t num{};
	cin >> num;

	/* vec space(num + 1, -1);
	cout << minimum_operations(num, space) << endl; */

	cout << minimum_operations_tabulation(num) << endl;

	return 0;
}
