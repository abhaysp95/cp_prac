// 2260. Minimum Consecutive Cards to Pick Up

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// naive approach (ofcourse, you'll get TLE)
    int minimumCardPickup_naive(vector<int>& cards) {
        size_t min_distance{cards.size()};
        bool is_pair_found{false};
        for (size_t i{}; i < cards.size(); i++) {
            for (size_t j{i + 1}; j < cards.size(); j++) {
                if (cards[i] == cards[j]) {
                    is_pair_found = true;
                    min_distance = min(min_distance, (j - i + 1));
                }
            }
        }
        return is_pair_found ? min_distance : -1;
    }

	// better approach (using unordered_map)
	int minimumCardPickup(vector<int>& cards) {
			size_t min_distance = 1e5 + 1;
			unordered_map<int, int> umap{};  // key is card's value, value is card's index
			bool is_card_found{false};
			for (size_t i{}; i < cards.size(); i++) {
				if (umap.find(cards[i]) != umap.end()) {
					is_card_found = true;
					min_distance = min(min_distance, i - umap[cards[i]] + 1);
				}
				umap[cards[i]] = i;
			}
			return is_card_found ? min_distance: -1;
		}
};
