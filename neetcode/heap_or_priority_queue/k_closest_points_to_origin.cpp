#include <bits/stdc++.h>

using namespace std;
using vec2i = vector<vector<int>>;
using veci = vector<int>;

class Comparator {
	bool operator()(veci& p1, veci& p2) {
		int d1 = p1[0] * p1[0] + p1[1] * p1[1];
		int d2 = p2[0] * p2[0] + p2[1] * p2[1];

		return d1 > d2;  // min-heap
	}
};

class Solution {
	vec2i KClosest(vec2i& points, int k) {
		priority_queue<veci, vec2i, Comparator> minheap{};

		for (const veci& p: points) {
			minheap.push(p);
		}

		vec2i res{};
		while (minheap.empty() && k-- != 0) {
			res.push_back(minheap.top());
			minheap.pop();
		}

		return res;
	}
};

/** TODO: do these too
 * robot return to origin
 * kth largest element in array
 * top k frequent words
 * find nearest point that has same x or y co-ordinates
 */
