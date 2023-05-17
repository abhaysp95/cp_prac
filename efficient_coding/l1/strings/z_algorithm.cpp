#include <bits/stdc++.h>

using namespace std;

vector<size_t> z_algo_unoptimized(const string& hay, const string& needle) {
	string wstr = needle + "$" + hay;
	vector<size_t> res{};

	vector<size_t> z_arr(wstr.size(), 0);

	/* size_t count = 0;
	bool match_set{false};
	size_t i = 1, j = 0, p = 0;
	while (i <= wstr.size()) {
		if (i == wstr.size() || wstr[i] != wstr[j]) {
			// when not matched store the total matched, to the point from where it started matching and reset i back to that point
			if (match_set) {
				i = p;
				match_set = false;
			}
			j = 0;
			z_arr[i] = count;
			count = 0;
		} else {  // matched
			// if matched, store the point from where it starts matching
			if (!match_set) {
				p = i;
				match_set = true;
			}
			j++, count++;
		}
		i++;
	} */

	size_t i = 0, j  = 0, count = 0;
	while (i < wstr.size()) {
		z_arr[i] = count;
		i++, j = 0, count = 0;
		size_t k = i;
		while (k < wstr.size()) {
			if (wstr[k] != wstr[j]) {
				break;
			}
			k++, j++, count++;
		}
	}

	for (size_t i = 0; i < z_arr.size(); i++) {
		cout << z_arr[i]  << " ";
		if (z_arr[i] == needle.size()) {
			res.push_back(i - needle.size() - 1);
		}
	}
	cout << endl;

	return res;
}

int main(void) {
	// string hay{"aabdaafabaabdf"}, needle{"aabdf"};
	string hay{"ababaa"}, needle{"aba"};

	vector<size_t> matched_idx = z_algo_unoptimized(hay, needle);
	for (const int x: matched_idx) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
