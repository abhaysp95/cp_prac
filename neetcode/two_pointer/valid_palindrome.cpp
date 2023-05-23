// https://leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // stringstream ss{};
        string temp{};
        temp.reserve(s.size());
        for (const char c: s) {
            if (isalnum(c)) {
                temp += tolower(c);
            }
        }

        // string temp = ss.str();
        cout << temp << endl;
        size_t tsz = temp.size() / 2;
        for (size_t i = 0; i < tsz; i++) {
            if (temp[i] != temp[temp.size() - i - 1]) {
                return false;
            }
        }

        return true;
    }
};

//NOTE: next do, https://leetcode.com/problems/valid-palindrome-ii/
