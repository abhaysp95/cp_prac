#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int lastStoneWeight(vector<int>& stones) {
			priority_queue<int> maxheap{};

			for (const int x: stones) {
				maxheap.push(x);
			}

			while (maxheap.size() > 1) {
				int s1 = maxheap.top(); maxheap.pop();
				int s2 = maxheap.top(); maxheap.pop();
				if (s1 != s2) {
					maxheap.push(s1 - s2);  // s1 will always be greater than s2, thus no abs()
				}
			}

			return maxheap.empty() ? 0 : maxheap.top();
		}

		// brute force way

		int lastStoneWeight_brute_force(vector<int>& weight) {
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
				// printf("midx, smidx: %d, %d\n", midx, smidx);
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

/** TODO: do these too
 * last stone weight 2
 * reduce array size to half
 * minimum time to make rope colorful
 * partition to k equal sum subsets
 */
