#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split_string(const std::string& input, std::string sep) {
	std::vector<std::string> words;
	size_t start{input.find_first_not_of(sep)}, end{};

	while (start != std::string::npos) {
		end = input.find_first_of(sep, start + 1);
		if (end == std::string::npos) {
			end = input.size();
		}

		words.emplace_back(input.substr(start, end));
		start = input.find_first_not_of(sep, end + 1);
	}

	return words;
}

/** easy split */
std::vector<std::string> easy_split(const std::string& input, char sep) {
	std::stringstream stream{input};

	std::vector<std::string> words{};
	std::string token;
	while (std::getline(stream, token, sep)) {
		words.push_back(token);
	}

	return words;
}

void reverse_words(std::vector<std::string>& words) {
	// std::vector<std::string>::iterator iter = words.begin();
	// std::vector<std::string>::reverse_iterator riter = words.rbegin();

	size_t len = words.size();
	for (size_t i{}; i < len / 2; i++) {
		std::swap(words[i], words[len - i - 1]);
	}
}

std::string join_words(const std::vector<std::string>& words, std::string sep) {
	if (0 == words.size()) return "";

	std::string res{};
	res.reserve(words.size() * 2 - 1);
	for (size_t i{}; i < words.size() - 1; i++) {
		res.append(words[i]);
		res.append(sep);
	}
	res.append(words[words.size() - 1]);

	return res;
}

/** naive python approach */
void solution1(const std::string& input, std::string sep) {
	std::vector<std::string> words = split_string(input, sep);
	reverse_words(words);
	std::cout << join_words(words, sep) << '\n';
}

int main(void) {
	std::string input;
	std::string sep = ".";

	while (std::getline(std::cin, input)) {
		std::string res{};
		res.reserve(input.size());

		long len{static_cast<long>(input.size())}, ppos{len - 1};
		for (long i = len - 1; i >= 0; i--) {
			if ('.' == input[i]) {
				res.append(input.substr(input[i + 1], ppos - i));
				ppos = i - 1;
				res.append(".");
			}
		}
		res.append(input.substr(0, ppos + 1));

		// problem
		/* std::string::reverse_iterator riter = input.rbegin();
		std::string::reverse_iterator temp_riter = riter;

		while (riter != input.rend()) {
			if ((riter + 1) != input.rend() && '.' == *(riter + 1)) {
				res.append(riter, temp_riter);
			} else if ('.' == *riter) {
				temp_riter = riter + 1;
			}
			riter++;
		} */

		std::cout << res << '\n';
	}

	std::cout << std::endl;

	return 0;
}
