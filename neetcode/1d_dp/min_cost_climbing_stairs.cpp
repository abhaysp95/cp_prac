#include <bits/stdc++.h>

using namespace std;
using veci = vector<int>;

class Solution {
	veci space{};
	public:
		int minCostClimbingStairs_memoized(veci& cost) {
			space.resize(cost.size(), -1);
			return min(min_cost(cost, 0), min_cost(cost, 1));
		}

		// memoized
		int min_cost(const veci& cost, size_t idx) {
			if (idx >= cost.size()) {
				return 0;
			}

			if (this->space[idx] != -1) {
				return this->space[idx];
			}

			return this->space[idx] = cost[idx] + min(min_cost(cost, idx + 1), min_cost(cost, idx + 2));
		}

		int minCostClimbingStairs(veci& cost) {
			cost.push_back(0);

			// 2 <= cost.size() <= 1000
			for (int i = cost.size() - 2; i >= 0; i--) {
				/* if (i + 2 < cost.size()) {  // due to the size constraint this check is unnecesary (cause now, size() >= 3)

				} */
				cost[i] += min(cost[i + 1], cost[i + 2]);
			}

			return min(cost[0], cost[1]);
		}
};

/** TODO: do these too
 * gas station
 * minimum money required before transaction
 * maximum security increasing cells in matrix
 * meeting scheduler
 * minimize product sum of two arrays
 */
