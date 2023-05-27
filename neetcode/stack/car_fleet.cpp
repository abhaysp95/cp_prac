// https://leetcode.com/problems/car-fleet/

#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		/** easy intuition is to consider, speed as x-axis and time as y-axis
		 * while moving with their respective speed, if the car crosses any other car
		 * before (or equal) to reaching target position, then they will form the
		 * fleet
		 */
		int carFleet(int target, vector<int> &position, vector<int> &speed) {

			if (position.size() <= 1)
				return position.size();

			size_t sz = speed.size();
			vector<pair<int, int>> right_order(sz);
			// right_order.reserve(sz);
			for (size_t i = 0; i < sz; i++) {
				right_order[i] = std::make_pair(position[i], speed[i]);
			}

			// arranging the cars with their increasing order of position
			sort(right_order.begin(), right_order.end(),
					[](const pair<int, int> &p1, const pair<int, int> &p2) {
					return p1.first < p2.first;
					});

			stack<pair<int, int>> st{};
			st.push(right_order[sz - 1]);

			for (int i = right_order.size() - 2; i >= 0; i--) {
				pair<int, int> ahead = st.top();
				double tt_ahead = (target - ahead.first) / (double)ahead.second;
				pair<int, int> behind = right_order[i];
				double tt_behind = (target - behind.first) / (double)behind.second;

				// if any car crosses the car ahead of it (that is takes less time to reach target than car
				// ahead of it), it'll be considered part of fleet with the car ahead of it, thus not
				// pushed in stack
				if (tt_behind > tt_ahead) {
					st.push(behind);
				}
			}

			return st.size();
		}
};

/** TODO: more
 * https://leetcode.com/problems/car-fleet-ii/description/
 * https://leetcode.com/problems/count-collisions-on-a-road/description/
 */


