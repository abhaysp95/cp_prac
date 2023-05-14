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

int main(void) {
	string input{};
	cin >> input;

	vector<int> code{};
	for (char c: input) {
		code.push_back(c - '0');
	}

	cout << decoded_ways(code, 0) << endl;

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
