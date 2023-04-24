#include <bits/stdc++.h>

size_t minimum_coins(int total_value);


int main(void) {
	int total_value = 121;  // 70

	size_t res = minimum_coins(total_value);
	printf("minimum coins: %zu\n", res);

	return 0;
}

size_t minimum_coins(int total_value) {
	size_t coin_count = 0;
	int coins[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

	int idx = 0;
	for (; idx < 9; idx++) {
		if (coins[idx] >= total_value) {
			if (coins[idx] > total_value) {
				idx--;
			}
			break;
		}
	}
	while (total_value && idx >= 0) {
		int count = total_value / coins[idx];  // question says, infinite supply of coins
		coin_count += count;
		total_value -= (coins[idx] * count);
		idx--;
	}

	return coin_count;
}
