#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> sorted{};
        sorted.reserve(strs.size());

        for (size_t i = 0; i < strs.size(); i++) {
            string to_sort = strs[i];
            sort(to_sort.begin(), to_sort.end());
            sorted.push_back({strs[i], to_sort});
        }

        sort(sorted.begin(), sorted.end(), [](const pair<string, string>& p1, const pair<string, string>& p2) {
            return p1.second < p2.second;
        });

        vector<vector<string>> res{};
        size_t idx = 1;
        vector<string> temp{};
        temp.push_back(sorted[0].first);

        while (idx < strs.size()) {
            if (sorted[idx].second != sorted[idx - 1].second) {
                res.push_back(temp);
                temp.clear();
            }
            temp.push_back(sorted[idx].first);
            idx++;
        }

        if (!temp.empty()) {
            res.push_back(temp);
        }

        return res;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
		unordered_map<string, vector<string>> umap{};

		for (const string x: strs) {
			string tstr = x;
			sort(tstr.begin(), tstr.end());
			umap[tstr].push_back(x);
		}

		vector<vector<string>> res{};
		for (const pair<string, vector<string>>& p: umap) {
			res.push_back(p.second);
		}

		return res;
	}
};
