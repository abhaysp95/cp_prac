#include <bits/stdc++.h>

using namespace std;

size_t decoded_ways(const vector<int>& code, size_t idx) {
	if (idx == code.size()) {
		return 1;
	}

	size_t res{};

	// if you get 0, then the further decoding would be wrong in both cases +1 & +2, thus return
	if (code[idx] != 0) {
		res += decoded_ways(code, idx + 1);
		if (idx + 1 < code.size()) {
			int num = code[idx] * 10 + code[idx + 1];
			if (num <= 26)
				res += decoded_ways(code, idx + 2);
		}
	}

	return res;
}

size_t decoded_ways(const vector<int>& code, size_t idx, vector<int>& space) {
	if (idx == code.size()) {
		return 1;
	}

	if (space[idx] != -1) {
		return space[idx];
	}

	size_t res{};

	// if you get 0, then the further decoding would be wrong in both cases +1 & +2, thus return
	if (code[idx] != 0) {
		res += decoded_ways(code, idx + 1, space);
		if (idx + 1 < code.size()) {
			int num = code[idx] * 10 + code[idx + 1];
			if (num <= 26)
				res += decoded_ways(code, idx + 2, space);
		}
	}

	return space[idx] = res;
}

// TODO: not correct, fix it (if you want to change it exactly same as memoized solution)
/* size_t decoded_ways_tabulation(const vector<int>& code) {
	vector<int> space(code.size() + 1, 0);
	space[0] = 1;

	for (size_t idx = 1; idx <= code.size(); idx++) {
		if (code[idx - 1] != 0) {
			space[idx] += space[idx - 1];
			if (idx > 1) {
				int num = code[idx - 1] * 10 + code[idx - 2];
				if (num <= 26) {
					space[idx] += space[idx - 2];
				}
			}
		} else {
			space[idx - 1] -= 1;
			space[idx] = space[idx - 1];
		}
	}

	return space[code.size()];
} */

// NOTE: if we move backwards of code to decode it, same solution can be used in
// both recursive and tabulation way. Here's how to do it
// recursively memoized way
size_t decoded_ways_reverse(const vector<int>& code, size_t idx, vector<int>& space) {
	if (idx == 0) {
		return 1;
	}

	if (space[idx] != -1) {
		return space[idx];
	}

	size_t sum{};
	if (code[idx - 1] != 0) {
		sum += decoded_ways_reverse(code, idx - 1, space);
	}
	if (idx > 1 && code[idx - 2] != 0) {
		int num = code[idx - 2] * 10 + code[idx - 1];
		if (num <= 26) {
			sum += decoded_ways_reverse(code, idx - 2, space);
		}
	}

	return space[idx] = sum;
}

size_t decoded_ways_reverse_tabulation(const vector<int>& code) {
	vector<int> space(code.size() + 1, -1);
	space[code.size()] = 1;

	for (size_t i = code.size(); i > 0; i--) {
		if (code[i - 1] == 0) {
			space[i - 1] = 0;  // main thing to keep in mind
		} else {
			space[i - 1] = space[i];
			if (i + 1 <= code.size()) {  // index not for last element
				int num = code[i - 1] * 10 + code[i];
				if (num <= 26) {
					space[i - 1] += space[i + 1];  // already added space[i] 4 lines above
				}
			}
		}
	}

	return space[0];
}

size_t decoded_ways_reverse_tabulation_space_optimized(const vector<int>& code) {

	size_t p1 = 1, p2 = 0;
	for (size_t i = code.size(); i > 0; i--) {
		size_t res{};
		if (code[i - 1] == 0) {
			res = 0;
		} else {
			res = p1;
			if (i + 1 <= code.size()) {
				int num = code[i - 1] * code[i];
				if (num <= 26) {
					res += p2;
				}
			}
		}
		p2 = p1;
		p1 = res;
	}

	return p1;
}

int main(void) {
	size_t T{};
	cin >> T;

	while (T--) {
		string input{};
		cin >> input;

		vector<int> code{};
		for (char c: input) {
			code.push_back(c - '0');
		}

		// vector<int> space(code.size(), -1);
		/* cout << decoded_ways_reverse(code, 0, space) << endl;
		for (int x: space) {
			cout << x << " ";
		}
		cout << "\n**********" << endl; */

		// cout << decoded_ways_tabulation(code) << endl;


		/* vector<int> space(code.size() + 1, -1);
		cout << decoded_ways_reverse(code, code.size(), space) << endl; */

		// cout << decoded_ways_reverse_tabulation(code) << endl;
		cout << decoded_ways_reverse_tabulation_space_optimized(code) << endl;
	}

	return 0;
}

/** inputs:
 * 12
 * 226
 * 1110
 * 11106
 * 111068
 * 111026
 */
