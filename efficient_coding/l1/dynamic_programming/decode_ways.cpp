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

// TODO: not correct, fix it
size_t decoded_ways_tabulation(const vector<int>& code) {
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
		}
	}

	return space[code.size()];
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

		vector<int> space(code.size(), -1);
		cout << decoded_ways(code, 0, space) << endl;
		for (int x: space) {
			cout << x << " ";
		}
		cout << "\n**********" << endl;

		// cout << decoded_ways_tabulation(code) << endl;
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
