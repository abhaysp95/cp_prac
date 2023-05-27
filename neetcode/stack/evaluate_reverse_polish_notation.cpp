// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st{};

        for (const string x: tokens) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                if (st.size() >= 2) {
                    int second = st.top();
                    st.pop();
                    int first = st.top();
                    st.pop();
                    int res = 0;
                    if (x == "+") res = first + second;
                    else if (x == "-") res = first - second;
                    else if (x == "*") res = first * second;
                    else if (x == "/") res = first / second;
                    st.push(res);
                }
            } else {
                st.push(stoi(x));
            }
        }

        return st.top();
    }
};

/** NOTE: try
 * https://leetcode.com/problems/evaluate-division/
 * https://leetcode.com/problems/basic-calculator/description/
 * https://leetcode.com/problems/expression-add-operators/description/
 */
