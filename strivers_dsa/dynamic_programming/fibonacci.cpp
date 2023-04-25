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

int fib_tabular(int n) {
	if (0 == n || 1 == n) {
		return n;
	}

	int buf[n + 1];
	memset(buf, -1, sizeof(buf));

	buf[0] = 0;
	buf[1] = 1;

	for (size_t i = 2; i <= n; i++) {
		buf[i] = buf[i - 1] + buf[i - 2];
	}

	return buf[n];
}

int main(void) {
	int num = 0;
	scanf("%d", &num);

	// printf("fib_recursive: %d\n", fib_recursive(num));

	/* memset(arr, -1, sizeof(arr));
	printf("fib_memoization: %d\n", fib_memoization(num)); */

	printf("fib_tabular: %d\n", fib_tabular(num));

	return 0;
}
