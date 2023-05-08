#include <bits/stdc++.h>
#include <cstring>
#include <unordered_map>

using namespace std;

ssize_t kmp_algo(const string& haystack, const string& needle) {

	int space[needle.size()];
	memset(space, 0, sizeof(space));

	// fill up space
	// (using hashmap)
	unordered_map<int, size_t> umap{};
	for (size_t i = 0; i < needle.size(); i++) {
		if (umap.find(needle[i]) != umap.end()) {
			space[i] = umap[needle[i]];
		}
		umap[needle[i]] = i + 1;
	}

	string temp_needle = " " + needle;

	// find match
	size_t i{}, j{};
	while (i < haystack.size() && j < needle.size()) {
		if (haystack[i] == temp_needle[j + 1]) {
			i++, j++;
		} else {
			if (j == 0) {
				i++;
			} else {
				j = space[j - 1];
			}
		}
		// printf("i: %zu, j %zu\n", i, j);
	}

	if (j == needle.size()) {
		return i - j;
	}

	return -1;
}

ssize_t kmp_algo2(const string& haystack, const string& needle) {

	int space[needle.size()];
	memset(space, -1, sizeof(space));

	// fill up space
	// (using hashmap)
	unordered_map<int, size_t> umap{};
	for (size_t i = 0; i < needle.size(); i++) {
		if (umap.find(needle[i]) != umap.end()) {
			space[i] = umap[needle[i]];
		}
		umap[needle[i]] = i;
	}

	// string temp_needle = " " + needle;

	// find match
	size_t i{};
	ssize_t j{-1};
	while (i < haystack.size() && j + 1 < needle.size()) {
		if (haystack[i] == needle[j + 1]) {
			i++, j++;
		} else {
			if (j == -1) {
				i++;
			} else {
				j = space[j];
			}
		}
		// printf("i: %zu, j %zu\n", i, j);
	}

	if (j + 1 == needle.size()) {
		return i - j - 1;
	}

	return -1;
}


int main(void) {
	string haystack{"ababcabcabababd"}, needle{"ababd"}; /* haystack{"abcdabcabcdf"}, needle{"abcdf"}; */

	cout << kmp_algo2(haystack, needle) << endl;

	return 0;
}
