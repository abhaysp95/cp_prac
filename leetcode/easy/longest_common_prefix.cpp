#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
	public:
		string longestCommonPrefix(vector<string>& strs)
		{
			size_t cmn{};
			size_t minl = 1e9;
			for (string s: strs)
				if (minl > s.size())
					minl = s.size();

			bool brk = false;
			for (size_t x = 0; x < minl; x++) {
				for (size_t y = 0; y < strs.size() - 1; y++) {
					if (strs[y][x] != strs[y + 1][x]) {
						brk = true;
						break;
					}
				}
				if (brk)
					break;
				cmn++;
			}

			return strs[0].substr(0, cmn);
		}
};

int main (int argc, char *argv[])
{
	Solution sol{};
	vector<string> strs{};
	string input{};
	while (getline(cin, input))
		strs.push_back(input);
	cout << "--------------------\n";
	for (auto x: strs)
		cout << x << " ";
	cout << "\n-----------------------\n";
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}

// https://stackoverflow.com/questions/34318489/is-it-true-that-sorting-strings-is-on2logn/34318565
// https://dj55427.medium.com/why-the-time-complexity-of-sorting-a-string-array-is-o-n-s-logn-not-o-n-logn-6548eabd7933
