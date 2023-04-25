#include <bits/stdc++.h>

int fib_recursive(int n) {
	if (0 == n || 1 == n) return n;

	return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main(void) {
	int num = 0;
	scanf("%d", &num);

	printf("fib_recursive: %d\n", fib_recursive(num));
	return 0;
}
