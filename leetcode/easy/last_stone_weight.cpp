// https://leetcode.com/problems/last-stone-weight/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
	int last_stone_weight(vector<int>& weight) {
		int midx = 0, smidx = 0;
		while (true) {
			// find max
			int temp = -1;
			for (int i = 0; i < weight.size(); i++) {
				if (weight[i] != -1) {
					if (weight[i] > temp) {
						temp = weight[i];
						midx = i;
					}
				}
			}
			if (temp == -1) {  // all weights are destroyed
				return 0;
			}
			// find second max
			temp = -1;
			for (int i = 0; i < weight.size(); i++) {
				if (weight[i] != -1) {
					if (weight[i] > temp && i != midx) {
						temp = weight[i];
						smidx = i;
					}
				}
			}
			if (temp == -1) {  // only one element left
				return weight[midx];
			}
			printf("midx, smidx: %d, %d\n", midx, smidx);
			if (weight[midx] == weight[smidx]) {
				weight[midx] = -1;
				weight[smidx] = -1;
			} else {
				weight[midx] = weight[midx] - weight[smidx];
				weight[smidx] = -1;  // weight -1 shows that weight is destroyed
			}
		}
	}
};

int main(void) {
	vector<int> stones = {2, 7, 4, 1, 8, 1};

	Solution sol{};
	printf("%d\n", sol.last_stone_weight(stones));

	return 0;
}
