// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res{};
        getParens(n, 0, 0, "", res);

        return res;
    }

    void getParens(int n, int o, int c, string cur, vector<string>& res) {
        if (o == n && c == n) {
            res.push_back(cur);
            return;
        }

        if (o == c) {
            getParens(n, o + 1, c, cur + "(", res);
        } else if (o == n) {
            getParens(n, o, c + 1, cur + ")", res);
        } else {
            getParens(n, o + 1, c, cur + "(", res);
            getParens(n, o, c + 1, cur + ")", res);
        }
    }
};

/** NOTE: do these too
 * https://leetcode.com/problems/generate-the-invoice/
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/
 */
