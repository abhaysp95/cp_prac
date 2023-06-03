// https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion_brute_force(string s1, string s2) {
        sort(s1.begin(), s1.end());

        for (size_t i = 0; i < s2.size(); i++) {
            for (size_t j = i + 1; j <= s2.size(); j++) {  // j is exclusive
                string t = s2.substr(i, (j - i));
                sort(t.begin(), t.end());
                if (s1 == t) {
                    return true;
                }
            }
        }

        return false;
    }

    bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) return false;

		vector<int> arr1(26, 0), arr2(26, 0);
		for (size_t i = 0; i < s1.size(); i++) {
			arr1[s1[i] - 'a']++;
			arr2[s2[i] - 'a']++;
		}

		size_t matches = 0;
		for (size_t i = 0; i < 26; i++) {
			if (arr1[i] == arr2[i]) matches++;
		}

		size_t l = 0, r = s1.size();  // make the window
		while (r < s2.size()) {
			if (matches == 26) return true;

			size_t idx = s2[r] - 'a';
			arr2[idx]++;
			if (arr1[idx] == arr2[idx]) matches++;
			else if (arr1[idx] == arr2[idx] - 1) matches--;  // it was matching before, I changed it now, thus "decrement"

			idx = s2[l] - 'a';
			arr2[idx]--;
			if (arr1[idx] == arr2[idx]) matches++;
			else if (arr1[idx] == arr2[idx] + 1) matches--;

			l--;
		}

		// in case the last char of s2 makes the match complete, check again
		if (matches == 26) return true;

		return false;
	}
};

/** TODO: do these too
 * https://leetcode.com/problems/percentage-of-letter-in-string/
 * https://leetcode.com/problems/minimum-window-substring/description/
 */
