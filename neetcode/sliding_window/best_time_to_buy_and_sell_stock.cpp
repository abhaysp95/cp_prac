#include <bits/stdc++.h>

using namespace std;

class Solution {
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;

		size_t l = 0, r = 1;

		size_t maxp = 0;
		while (r < prices.size()) {
			if (prices[l] < prices[r]) {
				maxp = max(maxp, (size_t)(prices[r] - prices[l]));
			} else {
				l = r;
			}
			r++;
		}

		return maxp;
	}
};
