#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int minimumIndex(vector<int>& nums) {
			unordered_map<int, int> freq{};
			int maxf = 0, maxn = 0;
			for (const int x: nums) {
				freq[x]++;
				if (maxf < freq[x]) {
					maxf = freq[x];
					maxn = x;
				}
			}

			size_t lfreq = 0;
			for (size_t i = 0; i < nums.size(); i++) {
				if (nums[i] == maxn) {
					lfreq++;
					if (lfreq * 2 > nums.size() / 2
							&& (maxf - lfreq) > nums.size() / 2) return i;
				}
			}

			return -1;
		}
};
