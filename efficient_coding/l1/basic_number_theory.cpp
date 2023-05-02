#include <bits/stdc++.h>

/**
 * (a + b) % c = ((a % c) + (b % c)) % c
 * (a * b) % c = ((a % c) * (b % c)) * C
 * (a - b) % c = ((a % c) - (b % c) + c) %c
 */

using namespace std;

const int MODULO = 1e9 + 7;  // first 10-digit prime and fits in the range of int data type

int main() {
	// find product of these numbers
	int arr[] = {1766342282, 874738772, 892884722};
	int len = sizeof(arr) / sizeof(int);

	int product = 1;
	for (int i = 0; i < len; i++) {
		product = (product * arr[i]) % MODULO;
	}

	cout << product << endl;
}
