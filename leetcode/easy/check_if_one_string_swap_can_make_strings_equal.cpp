#include <bits/stdc++.h>

using namespace std;

class Solution
{
	public:
		bool areAlmostEqual(string& s1, string& s2)
		{
			if (s1.size() != s2.size()) return false;

			int pidx{-1};  // shows that matching pair is satisfied
			size_t occur{};
			for (int i = 0; i < s1.size() && occur <= 2; i++) {  // occur <= 2, so that it can run extra iterations to check if there's
																 // more than two iteration in which case return false
				if (s1[i] != s2[i]) {
					if (occur == 2) return false; // no more than 2 mismatches
					occur++;
					if (occur > 1) {  // second mismatch
						if (s1[pidx] == s2[i] && s1[i] == s2[pidx]) {
							pidx = -1;
							continue;  // no need to change pidx in below line this time
						}
					}
					pidx = i;
				}
			}

			return occur <= 2 && (pidx == -1);
		}
};

int main (int argc, char *argv[])
{
	string s1{}, s2{};
	cin >> s1 >> s2;
	Solution sol{};
	cout << "size: " << s1.size() << ", " << s2.size() << endl;
	cout << (sol.areAlmostEqual(s1, s2) ? "True" : "False") << endl;
	return 0;
}
