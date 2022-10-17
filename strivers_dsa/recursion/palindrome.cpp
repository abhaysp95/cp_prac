#include <iostream>

using namespace std;

bool palindrome(const std::string& str, int x) {
	std::size_t sz = str.size();
	if (x == sz - x - 1) {
		return true;
	} else if (std::tolower(str[x]) != std::tolower(str[sz - x - 1])) {
		return false;
	}
	return palindrome(str, x + 1);
}

int main(void) {
	std::string str{};
	std::cin >> str;
	std::cout << (palindrome(str, 0) ? "true" : "false") << std::endl;
	return 0;
}
