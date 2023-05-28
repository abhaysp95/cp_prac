// https://leetcode.com/problems/koko-eating-bananas/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// brute force solution
    int minEatingSpeed(vector<int>& piles, int h) {
        size_t maxp = 0;
        for (const int x: piles) {
            maxp = max(maxp, (size_t)x);
        }

        bool found_min_hour = false;
        size_t i{};
        for (i = 1; i <= maxp; i++) {
            size_t tp = 0;
            for (size_t p = 0; p < piles.size(); p++) {
                tp += (piles[p] % i == 0 ? piles[p] / i : (piles[p] / i) + 1);
                if (tp > h) {
                    break;
                }
            }
            // cout << tp << '\n';
            if (tp == h) break;
        }

        return i;
    }

	// better (binary search version)
    int minEatingSpeed2(vector<int>& piles, int h) {
        size_t maxp{};

        for (const int x: piles) {
            maxp = max(maxp, (size_t)x);
        }

        size_t start = 1, end = maxp + 1;  // end is exclusiv

        size_t min_tt = maxp + 1;
        while (start < end) {
            size_t mid = start + (end - start) / 2;
            size_t tt = atleast_time_taken_to_eat(piles, mid, h);
            // cout << tt << " " << mid << '\n';
            /* if (tt == h) { // failing for some test case
                while (mid > 0) {
                    mid--;
                    tt = atleast_time_taken_to_eat(piles, mid, h);
                    if (tt != h) {
                        return mid + 1;
                    }
                }
                return 0;  // shouldn't reach here
            } else */ if (tt > h) {  // eat more bananas per hour
                start = mid + 1;
            } else {
				// it's possible that between a given range there can be multiple answers, thus keep checking between that range
                min_tt = min(min_tt, mid);  // done only because we are not doing (tt == h) seperately
                end = mid;
            }
        }

        return min_tt;
    }

    size_t atleast_time_taken_to_eat(const vector<int>& piles, size_t bpp, int h) {
        size_t tt{0};

        for (const int x: piles) {
            // tt += (x % bpp == 0 ? x / bpp : (x / bpp) + 1);
            tt += ceil(x / (double)bpp);
            if (tt > h) {
                break;
            }
        }

        return tt;
    }
};
