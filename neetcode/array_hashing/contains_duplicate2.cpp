// https://leetcode.com/problems/contains-duplicate-ii/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		bool containsNearbyDuplicate(vector<int>& nums, int k) {
			unordered_map<int, size_t> umap{};

			for (size_t i = 0; i < nums.size(); i++) {
				if (umap.find(nums[i]) != umap.end()) {
					if (i - umap[nums[i]] <= k) {
						return true;
					}
				}
				umap[nums[i]] = i;
			}

			return false;
		}
};

int main(void) {
	vector<int> vec{1,2,3,1,2,3};
	int k = 2;

	Solution solve{};
	cout << solve.containsNearbyDuplicate(vec, k) << endl;

	return 0;
}

// NOTE: solve contains-duplicate-iii
