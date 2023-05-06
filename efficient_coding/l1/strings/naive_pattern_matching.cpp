#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

ssize_t naive_pattern_matching(const string& haystack, const string& needle) {
	if (haystack.empty() || needle.empty()) return 0;

	size_t i{}, j{};

	while (i < haystack.size() && j < needle.size()) {
		if (haystack[i] == needle[j]) {
			printf("match i: %zu, j: %zu\n", i, j);
			j++;
		} else {
			printf("not match [before reset] i: %zu, j: %zu\n", i, j);
			if (j != 0) i -= j;
			j = 0;
			printf("not match [after reset] i: %zu, j: %zu\n", i, j);
		}
		i++;
	}

	if (j == needle.size()) {  // found match
		return i - j;
	}

	return -1;
}

int main(void) {
	string haystack{"abcdabcabcdf"}, needle{"abcdf"};

	cout << naive_pattern_matching(haystack, needle) << endl;

	return 0;
}
