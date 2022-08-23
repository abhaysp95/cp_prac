#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		// solution works better for big numbers like: 1234567899
		bool isPalindrome(int x)
		{
			if (x < 0 || (x != 0 && x % 10 == 0))
				return false;

			int res = 0;
			while (x > res) {
				res = ((res * 10) + (x % 10));
				x /= 10;
			}
			return (x == res) || (x == (res / 10));
		}
};

int main (int argc, char *argv[])
{
	int x{};
	cin >> x;
	Solution sol;
	cout << (sol.isPalindrome(x) ? "true" : "false") << endl;
	return 0;
}


	/* if (x < 0)
		x = -x;
	int temp = x;
	int y = 0;
	while (temp != 0) {
		int res = temp % 10;
		y = (y * 10) + res;
		temp /= 10;
	}
	cout << ((x == y) ? "true" : "false") << endl; */
