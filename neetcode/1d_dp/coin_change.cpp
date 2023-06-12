#include <bits/stdc++.h>

using namespace std;

class Solution {
	vector<vector<int>> space{};
	public:
		int coinChange(vector<int>& coins, int amount) {
			/* this->space.resize(coins.size(), vector<int>(amount + 1, -1));
			int res = _coin_change(coins, amount, coins.size() - 1);
			return res >= 1e9 ? -1 : re; */

			this->space.resize(coins.size(), vector<int>(amount + 1, 0));
			for (int i = 0; i <= amount; i++) {
				this->space[0][i] = amount % coins[0] == 0 ? (amount / coins[0]) : 1e9;
			}

			for (int i = 1; i < coins.size(); i++) {
				for (int j = 0; j <= amount; j++) {
					int notake = this->space[i - 1][j];
					int take = INT_MAX;
					if (j >= coins[i]) {
						take = 1 + this->space[i - 1][j - coins[i]];
					}
					this->space[i][j] = min(take, notake);
				}
			}

			int res = this->space[coins.size() - 1][amount];
			return res >= 1e9 ? -1 : res;
		}

		int _coin_change(const vector<int>& coins, int amount, int idx) {
			if (idx == 0) {
				if (amount % coins[idx] == 0) return amount / coins[idx];
				return 1e9;
			}

			if (this->space[idx][amount] != -1) {
				return this->space[idx][amount];
			}

			int notake = _coin_change(coins, amount, idx - 1);
			int take = INT_MAX;
			if (amount >= coins[idx]) {
				take = 1 + _coin_change(coins, amount - coins[idx], idx - 1);
			}

			return this->space[idx][amount] = min(notake, take);
		}
};
