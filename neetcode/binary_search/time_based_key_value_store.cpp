// https://leetcode.com/problems/time-based-key-value-store/

#include <bits/stdc++.h>

using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<size_t, string>>> _umap{};
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        this->_umap[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (this->_umap.find(key) == this->_umap.end()) {
            return "";
        }
        vector<pair<size_t, string>>& vec = this->_umap[key];

        size_t start = 0, end = vec.size(), mid = 0;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (vec[mid].first == timestamp) {
                break;
            } else if (vec[mid].first < timestamp) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        // if there is nothing before mid, return ""
        if (mid == 0 && vec[mid].first > timestamp) {
            return "";
        }
        return vec[mid].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/**
 * TODO: do these to
 * https://leetcode.com/problems/base-7/
 * https://leetcode.com/problems/stock-price-fluctuation/description/
 */
