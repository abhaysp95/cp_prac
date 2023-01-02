#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

#define INF 1e6

using vec = std::vector<int>;
using vec_citer = std::vector<int>::const_iterator;

// Given an array and a sum k, we need to print the length of the longest
// subarray that sums to k.

size_t longest_subarray_with_sum_optim(const vec& arr, int k) {
	int max_len = 0;

	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = i + 1; j <= arr.size(); j++) {
			int sum = std::accumulate(arr.cbegin() + i, arr.cbegin() + j, 0);
			if (sum == k) {
				int len = j - i;
				max_len = std::max(max_len, len);
			} else if (sum > k) {
				break;
			}
		}
	}

	return max_len;
}

// using sliding index
// how to do it
/* Here we have 2 nested loops. The outer loop slides the starting index of the window towards the right. The inner loop slides the ending index of the window towards the right.
Here is the working. First we fix the starting index and increase the ending index which increases the window size. We do this until we get the sum greater than k or we go out of bounds.
If we get a greater sum, we come out of the inner loop. We check whether we have got the sum, if so, now we compare with the max length we found so far, and replace it with the greatest.
Now, it’s time for us to shift the starting index, therefore we subtract the current starting element from the sum(meaning that we don’t include that number hereafter).
And we increase the start index which in turn decreases the window size. Now we can go on increasing the ending index as we did earlier. */

size_t longest_subarray_with_sliding_window(const vec& arr, int k) {
	int start = 0, end = -1, max_length = 0, sum = 0;

	while (start < arr.size()) {
		while((end + 1 < arr.size()) && (sum + arr[end + 1] <= k))
			sum += arr[++end];

		if (sum == k) {
			max_length = std::max(max_length, (end - start + 1));
		}

		sum -= arr[start];
		start++;
	}

	return max_length;
}

size_t longest_subarray_with_sum(const vec& arr, int k) {
	vec::difference_type dist = 0;

	vec_citer citer = arr.cbegin();
	while (citer != arr.cend()) {
		vec_citer cjter = citer + 1;
		do {
			int sum = std::accumulate(citer, cjter, 0);
			if (sum == k) {
				dist = std::max(dist, std::distance(citer, cjter));
			} else if (sum > k) {
				break;
			}
			cjter++;
		} while(cjter != arr.cend());
		citer++;
	}

	return dist;
}

int main(void) {
	vec arr = {7,1,6,0};
	int k = 7;

	/* vec arr = {2, 3, 5, 1, 9};
	int k = 10; */

	printf("%zu\n", longest_subarray_with_sliding_window(arr, k));

	return 0;
}
