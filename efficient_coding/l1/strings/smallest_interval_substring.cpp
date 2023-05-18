#include <bits/stdc++.h>

// there is one hidden test case which this solution is passing but C++ solution
// is not, wonder what that is

using namespace std;
using vec = vector<size_t>;

vec get_factors(size_t len) {
	vec res{};
	/* while (len != 0) {
		res.push_back(len);
		len /= 2;
	} */
	for (size_t i = 1; i <= len / 2; i++) {
		if (len % i == 0) {
			res.push_back(i);
		}
	}
	return res;
}

bool interval_string(const string& input, size_t plen) {
	string wstr = input.substr(0, plen) + "$" + input;
	vec z_arr(wstr.size(), 0);

	size_t i = 0, j = 0, count = 0;
	while (i < wstr.size()) {
		z_arr[i] = count;
		i++, j = 0, count = 0;
		size_t k = i;
		while (k < wstr.size() && wstr[k] == wstr[j]) {
			k++, j++, count++;
		}
	}

	count = 0;
	for (size_t i = 0; i < z_arr.size(); i++) {
		cout << z_arr[i] << " ";
		if (z_arr[i] == plen) count++;
	}
	cout << endl;

	return (count * plen) == input.size();
}

int main(void) {
	string input{};
	cin >> input;

	if (input.size() % 2 == 1) {
		cout << input << endl;
	} else {
		size_t interval_len{input.size()};
		vec factors = get_factors(input.size());
		for (const size_t factor: factors) {
			if (interval_string(input, factor)) {
				interval_len = factor;
				break;
			}
		}
		cout << input.substr(0, interval_len) << endl;
	}

	return 0;
}
