// given array of +ve and -ve number (array is unsorted), find smallest missing +ve integer

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using vec = vector<int>;
using umap = unordered_map<int, size_t>;

int main(void) {
	vec arr{-5, 2, 0, -1, -10, 15};
	size_t sz = sizeof(arr) / sizeof(int);

	umap counts{};
	for (size_t i = 0; i < sz; i++) {
		if (arr[i] > 0) {
			counts[arr[i]] += 1;
		}
	}

	size_t smallest{1};
	while (true) {
		if (counts.find(smallest) == counts.end()) {
			break;
		}
		smallest++;
	}

	cout << "smallest +ve missing integer: " << smallest << endl;

	return 0;
}
