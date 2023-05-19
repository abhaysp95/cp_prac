#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	size_t T{};
	cin >> T;
	while (T--) {
		size_t start{}, end{};
		cin >> start >> end;

		size_t idx = start;
		size_t count{};
		while (idx <= end) {
			string sidx = to_string(idx);
			size_t lsidx = sidx.size();
			if (lsidx % 2 != 0) {
				idx *= 10;
				continue;
			}
			vector<int> arr{};
			for (const char c: sidx) {
				arr.push_back(c - '0');
			}
			size_t fsum = accumulate(arr.begin(), arr.begin() + lsidx / 2, 0);
			size_t ssum = accumulate(arr.begin() + lsidx / 2, arr.end(), 0);
			if (fsum == ssum) {
				count++;
			}

			binary_search(arr.begin(), arr.end(), 0);

			idx++;
		}


		cout << count << endl;
	}

	return 0;
}

/** input:
 * 1
 * 1 100
 */

// NOTE: above same solution can also be easily written in python in same way
