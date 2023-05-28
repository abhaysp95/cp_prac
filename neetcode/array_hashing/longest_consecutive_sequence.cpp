#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // this solution does believe that each element can be part of only one
  // consecutive sequence (which is obviously how it works)
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, bool> umap{};

    for (const int x : nums) {
      umap[x] = false;
    }

    size_t max_count{};
    for (const int x : nums) {
      size_t count{};
      if (umap[x]) {
        continue;
      }
      // check prev numbers
      int prev = x;
      while (true) {
        if (umap.find(--prev) == umap.end()) {
          break;
        }
        umap[prev] = true;
        count++;
      }
      int next = x;
      while (true) {
        if (umap.find(++next) == umap.end()) {
          break;
        }
        umap[next] = true;
        count++;
      }

      max_count = max(max_count, count + 1);
    }

    return max_count;
    }

  int longestConsecutive2(vector<int> &nums) {
	  int max_longest = 0;

	  unordered_set<int> us{};
	  for (const int x: nums) {
		  us.insert(x);
	  }

	  for (const int x: nums) {
		  if (us.find(x - 1) == us.end()) {  // no left neighbour (a new sequence starts)
			  int count = 0;  // from 0, means it'll also include itself in sequence
			  while (us.find(x + count) != us.end()) {
				  count++;
			  }

			  max_longest = max(max_longest, count);
		  }
	  }

	  return max_longest;
  }
};
