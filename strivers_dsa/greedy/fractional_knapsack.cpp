// unlink 0/1 knapsack, you can take fraction of a element. You can take one element, only one time

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using item = pair<int, int>;  // { value, weight }

int fractional_knapsack(vector<item>& items, int weight);

int main(void) {
	vector<item> items = {{60, 10}, {100, 20}, {120, 30}};
	int bag_weight = 50;

	int res = fractional_knapsack(items, bag_weight);
	printf("total profit: %d\n", res);

	return 0;
}

int fractional_knapsack(vector<item>& items, int weight) {
	sort(items.begin(), items.end(), [&](item x, item y) {
			float p1 = (float)x.first / x.second;
			float p2 = (float)y.first / y.second;
			return p1 > p2;
			});

	int idx = 0;
	int total_profit = 0;
	while (weight) {
		if (items[idx].second < weight) {
			weight -= items[idx].second;
			total_profit += items[idx].first;
			idx++;
		} else {
			float pr = (float)items[idx].first / items[idx].second;
			float value = pr * weight;
			total_profit += value;
			weight = 0;
		}
	}

	return total_profit;
}
