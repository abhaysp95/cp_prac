#include <bits/stdc++.h>
#include <cstring>

int arr[46];  // as per question 1 <= n <= 45

int recursive_ways(int n) {
	if (n == 1 || n == 0) return n;

	return recursive_ways(n - 1) + recursive_ways(n - 2);
}

int climbStairs(int n) {
	if (n == 1 || n == 0) return 1;

	if (-1 != arr[n]) {
		return arr[n];
	}

	arr[n] = climbStairs(n - 1) + climbStairs(n - 2);
	return arr[n];
}

int space_optimized_way(int n) {
	if (0 == n || 1 == n) return 1;

	int buf[2];
	memset(buf, -1, sizeof(buf));

	for (int i = 2; i <= n; i++) {
		int temp = buf[0] + buf[1];
		buf[0] = buf[1];
		buf[1] = temp;
	}

	return buf[1];
}

int main(void) {
	int num;
	scanf("%d", &num);

	memset(arr, -1, sizeof(arr));

	printf("%d\n", recursive_ways(num));
	return 0;
}
