#include <bits/stdc++.h>

using namespace std;
using veci = vector<int>;

class Solution {
	int findKthLargest(veci& nums, int k) {
		priority_queue<int> maxheap{};

		for (const int x: nums) {
			maxheap.push(x);
		}

		while (!maxheap.empty() && k-- > 1) {
			maxheap.pop();
		}

		return maxheap.top();
	}
};
