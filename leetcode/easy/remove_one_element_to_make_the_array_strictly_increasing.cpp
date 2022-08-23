#include <bits/stdc++.h>

using namespace std;

class Solution
{
	public:
		bool canBeIncreasing(vector<int>& nums)
		{
			/* size_t fincr = 0;
			for (size_t i = 0, j = i + 1; i < nums.size() - 1; i++, j++) {
				if (j == nums.size()) return fincr <= 1;
				if ((nums[i] > nums[j]) && !fincr)
					fincr++, i--;
				else if (nums[i] > nums[j])
					return false;
			}
			return true; */

			size_t cnt{};
			for (size_t i = 1; i < nums.size() && cnt < 2; i++) {
				// if drop
				if (nums[i] <= nums[i - 1]) {
					cnt++;
					if (i > 1 && (nums[i - 2] >= nums[i]))
						nums[i] = nums[i - 1];
				}
			}

			return cnt < 2;
		}
};

int main (int argc, char *argv[])
{
	vector<int> arr{};
	int x{};
	while (cin >> x) {
		arr.push_back(x);
	}
	Solution sol{};
	cout << (sol.canBeIncreasing(arr) ? "True" : "False") << endl;
	return 0;
}
