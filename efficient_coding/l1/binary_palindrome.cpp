#include <bits/stdc++.h>
#include <cstring>
#include <functional>

using ll = long long;
using namespace std;

bool is_bin_palindrome(ll);
bool is_palindrome_better(ll);

// bool space[2 * (int)1e9];

size_t binary_palindrome(ll num, size_t count) {
	if (is_bin_palindrome(num)) {
		return count;
	}

	int check_left = num - 1;
	int check_right = num + 1;

	while (true) {
		if (is_bin_palindrome(check_left)) {
			break;
		}
		check_left--;
	}

	while (true) {
		if (is_bin_palindrome(check_right)) {
			break;
		}
		check_right++;
	}

	return min(num - check_left, check_right - num);
}

bool is_bin_palindrome(ll num) {
	int len = 1;
	int temp = 1;

	while (temp < num) {
		temp <<= 1;
		len++;
	}
	if (temp > num) len--;

	// check palindrome
	for (int i = 0; i < len / 2; i++) {
		// left-most bit
		int lb = (num & (1 << i)) ? 1 : 0;
		int rb = (num & (1 << (len - i - 1))) != 0 ? 1 : 0;  // anything other than 0, means bit is on

		if (lb != rb) {
			return false;
		}
	}

	return true;
}

/* bool is_palindrome_better(ll num) {

	auto is_bit_set = [&](int k) {
		return (num & (1 << (k - 1))) ? true : false;
	};

	int l = 1;
	int r = sizeof(ll) * 8;

	while (l < r) {
		if (is_bit_set(l) != is_bit_set(r)) {
			return false;
		}
		l++, r--;
	}

	return true;
} */

int main(void) {
	ll num = 0;

	// memset(space, 0, sizeof(space));

	cin >> num;

	cout << binary_palindrome(num, 0) << endl;

	return 0;
}
