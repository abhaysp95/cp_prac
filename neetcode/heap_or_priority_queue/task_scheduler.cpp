#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		int leastInterval(vector<char>& tasks, int n) {
			priority_queue<int> maxheap{};
			unordered_map<char, size_t> freq{};
			queue<pair<size_t, size_t>> q{};

			for (const char c: tasks) {
				freq[c]++;
			}

			for (const pair<char, size_t>& p: freq) {
				maxheap.push(p.second);
			}

			size_t maxt = 0;
			while (!maxheap.empty() || !q.empty()) {
				maxt++;
				if (!maxheap.empty()) {
					size_t count = maxheap.top();
					maxheap.pop();
					if (count > 1) {
						q.push({count - 1, maxt + n});
					}
				}
				if (!q.empty() && maxt == q.front().second) {
					maxheap.push(q.front().first);
					q.pop();
				}
			}

			return maxt;
		}
};

/** TODO: do these too
 * task scheduler 2
 * rearrange string k distance apart
 * reorganize string
 * maximum number of weeks for which you can work
 */
