// https://leetcode.com/problems/palindrome-partitioning/editorial/

#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(const string& str, size_t start, size_t len);

void print_palindrome_substrings(const string& str, size_t start, vector<string>& curr, vector<vector<string>>& res) {
	if (start >= str.length()) {
		for (string& str: curr) {
			cout << str << " ";
		}
		cout << "\n---------------" << '\n';
		res.emplace_back(curr);
		return;
	}

	for (size_t i = start; i < str.size(); i++) {
		if (is_palindrome(str, start, i - start + 1)) {
			curr.push_back(str.substr(start, i - start + 1));
			print_palindrome_substrings(str, i + 1, curr, res);
			curr.pop_back();
		}
	}
}

// unordered_map<string, vector<string>> space;

void print_palindrome_substrings_memoized(const string& str, size_t start, vector<string>& curr, vector<vector<string>>& res, vector<vector<bool>>& space) {
	if (start >= str.length()) {
		for (string& str: curr) {
			cout << str << " ";
		}
		cout << "\n---------------" << '\n';
		res.emplace_back(curr);
		return;
	}

	for (size_t i = start; i < str.size(); i++) {
		// if (is_palindrome(str, start, i - start + 1)) {
		if (space[start] == space[i] && (i - start <= 2 || space[start + 1][i - 1])) {
			space[start][i] = true;
			curr.push_back(str.substr(start, i - start + 1));
			print_palindrome_substrings_memoized(str, i + 1, curr, res, space);
			curr.pop_back();
		}
	}
}

bool is_palindrome(const string& str, size_t start, size_t len) {
	string temp = str.substr(start, len);
	for (size_t i = 0; i < len / 2; i++) {
		if (temp[i] != temp[len - i - 1]) {
			return false;
		}
	}

	return true;
}


int main(void) {
	string str = "abbac";

	vector<string> curr{};
	vector<vector<string>> res{};
	print_palindrome_substrings(str, 0, curr, res);
	/* vector<vector<bool>> space(str.size(), vector<bool>(str.size(), false));
	print_palindrome_substrings_memoized(str, 0, curr, res, space); */

	cout << "**********************" << '\n';
	for (auto& row: res) {
		for (string& str: row) {
			cout << str << " ";
		}
		cout << '\n';
	}
	cout << endl;

	return 0;
}
