#include <bits/stdc++.h>
#include <cstring>

int fib_recursive(int n) {
	if (0 == n || 1 == n) return n;

	return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int arr[10001];

int fib_memoization(int n) {
	if (0 == n || 1 == n) {
		return n;
	}

	if (arr[n] != -1) {
		return arr[n];
	}

	arr[n] = fib_memoization(n - 1) + fib_memoization(n - 2);
	return arr[n];
}

int main(void) {
	int num = 0;
	scanf("%d", &num);

	// printf("fib_recursive: %d\n", fib_recursive(num));

	memset(arr, -1, sizeof(arr));
	printf("fib_memoization: %d\n", fib_memoization(num));

	return 0;
}
