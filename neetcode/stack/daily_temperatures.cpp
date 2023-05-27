// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

	// brute force version
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        if (temperatures.size() <= 1) {
            return res;
        }

        for (size_t i = 0; i < temperatures.size() - 1; i++) {
            for (size_t j = i + 1; j < temperatures.size(); j++) {
                if (temperatures[i] < temperatures[j]) {
                    res[i] = j - i;
                    break;
                }
            }
        }

        return res;
    }

	// better version ?
    vector<int> dailyTemperatures2(vector<int>& temperatures) {
		if (temperatures.size() == 0) return vector<int>{};

		vector<int> res(temperatures.size(), 0);
		stack<pair<int, size_t>> st{};  // {temperature, index}
		st.push({temperatures[0], 0});

		for (size_t i = 1; i < temperatures.size(); i++) {
			while (!st.empty() && temperatures[i] > st.top().first) {
				size_t idx = st.top().second;
				st.pop();
				res[idx] = i - idx;
			}
			st.push({temperatures[i], i});
		}

		return res;
	}
};
