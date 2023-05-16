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

int main(void) {
	size_t num{};
	cin >> num;

	vec space(num + 1, -1);
	cout << minimum_operations(num, space);

	return 0;
}
