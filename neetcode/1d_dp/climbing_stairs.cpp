#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		// space optimized solution
		int climbStairs(int n) {
			int zero = 1;  // apparently zero steps means 1 way
			int first = 1;
			for (int i = 2; i <= n; i++) {
				int res = zero + first;
				zero = first;
				first = res;
			}

			return first;
		}
};

// memoized solution
/* class Solution {
	public:
		Solution() {
			memset(this->arr, -1, sizeof(this->arr));
		}
		int climbStairs(int n) {
			if (n == 1 || n == 0) return 1;

			if (-1 != arr[n]) {
				return arr[n];
			}

			arr[n] = climbStairs(n - 1) + climbStairs(n - 2);
			return arr[n];

		}

	private:
		int arr[46];
}; */

/** TODO: do these too
 * https://leetcode.com/problems/min-cost-climbing-stairs/
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 * https://leetcode.com/problems/fibonacci-number/description/
 * https://leetcode.com/problems/n-th-tribonacci-number/description/
 */
