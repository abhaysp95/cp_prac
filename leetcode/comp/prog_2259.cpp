// 2259. Remove Digit From Number to Maximize Result
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        string res{};
        for (size_t i{}; i < number.size(); i++) {
            if (digit == number[i]) {
                string temp = number.substr(0, i) + number.substr(i + 1, number.size() - i);
                if (!max_string(res, temp)) {
                    res = temp;
                }
            }
        }
        return res;
    }
private:
	// you can use max() provided already, but this was just to test something
    bool max_string(string str1, string str2) {
        if (str1.size() != str2.size()) {
            return str1.size() > str2.size();
        } else {
            for (size_t i{}; i < str1.size(); i++) {
                int d1 = str1[i] - '0', d2 = str2[i] - '0';
                if (d1 > d2) return true;
                else if (d2 > d1) return false;
            }
        }
        return true;
    }
};
