#include <bits/stdc++.h>

using namespace std;

// wrong algo
/* int water_tank(const vector<int>& arr) {
	size_t i{}, j{arr.size() - 1};
	size_t max_area{0};

	while (i < j) {
		size_t cur_area = min(arr[i], arr[j]) * (j - i);
		max_area = max(max_area, cur_area);

		// next either left will move, or right will move, so whoever gives me bigger area will move
		if (arr[i + 1] < arr[j]) {
			j--;
		} else {
			i++;
		}

		// printf("i: %zu, j: %zu\n", i, j);
	}

	return max_area;
} */

// slightly better (not in TC, but still)
int water_tank(const vector<int>& arr) {
	size_t i{}, j{arr.size() - 1};
	size_t max_area{0};

	while (i < j) {
		size_t cur_area = min(arr[i], arr[j]) * (j - i);
		max_area = max(max_area, cur_area);

		// short height, already gave its best answer. Moving forward
		// with small height bar will only decrease the area (width is
		// decreasing in each iteration), so no need to check keeping
		// the minimum height same. Thus, we'll move the smaller height
		// one forward. Three possibilities:
		// 1. get_even_smaller_height than not moved one
		// 2. get_same_height as not moved one
		// 3. get_bigger_height than not moved one: Good
		if (i < j) {
			i++;
		} else {
			j--;
		}
	}

	return max_area;
}

int main(void) {
	vector<int> arr{6, 4, 2, 5, 4, 6, 1, 3, 5};

	cout << water_tank(arr) << endl;

	return 0;
}
