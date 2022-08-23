#include <bits/stdc++.h>

using namespace std;

class Solution
{
	public:
int romanToInt(string s) {
			unordered_map<char, int> rval{
				{'I', 1},
				{'V', 5},
				{'X', 10},
				{'L', 50},
				{'C', 100},
				{'D', 500},
				{'M', 1000} };

			int num = 0;
			for (size_t x = 0; x < s.length(); x++) {
				if ((x + 1) != s.length() && rval[s[x + 1]] > rval[s[x]])
					num += (rval[s[x + 1]] - rval[s[x]]), x++;
				else
					num += rval[s[x]];
			}
			return num;
		}
};

int main (int argc, char *argv[])
{
	Solution sol;
	string input;
	cin >> input;
	cout << sol.romanToInt(input) << endl;
	return 0;
}
