#include <bits/stdc++.h>

using namespace std;

// Jenny starts first
// if number to start is 1, Ben will win, since Jenny can't make the move

bool game_of_numbers(unsigned long num) {
	bool turn{true};

	// get reducer
	auto reducer = [&](unsigned long x) {
		unsigned long t{1};
		while (t < x) {
			t <<= 1;
		}

		if (t > x) {
			t >>= 1;
		}

		return t;
	};

	bool is_power_of_2{false};
	while (num != 1) {
		turn = !turn;

		if (!is_power_of_2) {
			unsigned long rr = reducer(num);
			printf("num: %lu, reducer: %lu\n", num, rr);
			if (rr == num) {
				is_power_of_2 = true;
				num >>= 1;
			} else {
				num -= rr;
			}
		} else {
			num >>= 1;
		}
	}

	return turn;
}

int main(void) {

	unsigned long num{};
	cin >> num;

	cout << (game_of_numbers(num) ? "Ben" : "Jenny") << endl;

	return 0;
}
