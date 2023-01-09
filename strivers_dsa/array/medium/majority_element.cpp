#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using vec = std::vector<int>;
using umap = std::unordered_map<int, size_t>;

// the result is floor(N/2) element

// using hashmap, and insert element everytime and increase the frequency
// not considering space complexity here, as hashmap can be used directly, instead of traversing from vector
int solution1(const vec& arr) {
	umap thash{};
	size_t limit{arr.size() / 2};

	for (const int& x: arr) {
		if (thash[x] >= limit) {
			return x;
		}
		thash[x]++;
	}

	return 0;
}

// Moore's voting algo
int solution2(const vec& arr) {
	int count = 0;
	int current = 0;

	for (int num: arr) {
		if (count == 0) {
			current = num;
		}
		if (num == current) count++;
		else count--;
	}

	return current;
}

int main(void) {
	// vec arr{2,2,1,1,1,2,2};
	vec arr{4,4,2,4,3,4,4,3,2,4};

	printf("%d\n", solution2(arr));

	return 0;
}
