#include <bits/stdc++.h>

/**
 * (a + b) % c = ((a % c) + (b % c)) % c
 * (a * b) % c = ((a % c) * (b % c)) * C
 * (a - b) % c = ((a % c) - (b % c) + c) %c
 */

using namespace std;

const int MODULO = 1e9 + 7;  // first 10-digit prime and fits in the range of int data type

void big_number_product() {
	int arr[] = {1766342282, 874738772, 892884722};
	int len = sizeof(arr) / sizeof(int);

	int product = 1;
	for (int i = 0; i < len; i++) {
		product = (product * arr[i]) % MODULO;
	}

	cout << product << endl;
}

int calculate_power_recursive(int n, int b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		return calculate_power_recursive(n * n, b / 2);
	} else {
		return n * calculate_power_recursive(n * n, (b - 1) / 2);
	}
}

int modular_exponentiation_recursive(int n, int b, int c) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		return modular_exponentiation_recursive((n * n) % c, b / 2, c);
	} else {
		return (n * modular_exponentiation_recursive((n * n) % c, b / 2, c)) % c;
	}
}

int modular_exponentiation_iteration(int n, int b, int c) {
	int result = 1;
	while (b != 0) {
		/* if (b % 2 == 0) {
			n = (n * n) % c;
		} else {
			result = (result * n) % c;
			n = (n * n) % c;
		}
		b /= 2; */
		if (b % 2 == 1) {
			result = (result * n) % c;
		}
		n = (n * n) % c;
		b = b / 2;
	}

	return result;
}

int gcd(int first, int second) {
	// base condition
	if (first % second == 0) {
		return second;
	}
	int third = first % second;
	return gcd(second, third);
}

int gcd_iterative(int first, int second) {
	while (first % second != 0) {
		int third = first % second;
		first = second;
		second = third;
	}

	return second;
}

int main() {
	cout << gcd(12, 20) << endl;
}
