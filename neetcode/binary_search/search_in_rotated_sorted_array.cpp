#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int search(vector<int>& arr, int target) {
			size_t start = 0, end = arr.size();

			while (start < end) {
				size_t mid = start + (end - start) / 2;

				if (arr[mid] == target) {
					return mid;
				} else if (arr[start] <= arr[mid]) {  // write conditions thinking you're on left sorted portion
					if (target > arr[mid] || target < arr[start]) {
						start = mid + 1;
					} else {
						end = mid;
					}
				} else {
					if (target < arr[mid] || target > arr[end - 1]) {  // end is exclusive
						end = mid;
					} else {
						start = mid + 1;
					}
				}
			}

			return -1;
		}
};
