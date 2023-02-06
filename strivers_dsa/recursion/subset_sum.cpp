#include <algorithm>
#include <bits/stdc++.h>
#include <cinttypes>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

ostream& print_arr(ostream& out, const vector<int>& res) {
	if (res.empty()) return out;
	out << '[';
	for (size_t i{}; i < res.size() - 1; i++) {
		out << res[i] << ',';
	}
	out << res[res.size() - 1] << ']';

	return out;
}

void subset_sum(size_t idx, int sum, const std::vector<int>& arr, std::vector<int>& res) {

	if (arr.size() == idx) {
		res.push_back(sum);
		return;
	}

	subset_sum(idx + 1, sum + arr[idx], arr, res);
	subset_sum(idx + 1, sum, arr, res);
}


int main(void) {
	std::string input{};

	std::vector<int> arr{};
	size_t count{};

	std::cin >> input;
	std::cin >> count;
	std::istringstream istream{input};

	std::string temp{};
	while (std::getline(istream, temp, ',')) {
		arr.push_back(std::stoi(temp));
	}

	std::vector<int> res{};
	res.reserve(pow(2, count));

	subset_sum(0, 0, arr, res);

	std::sort(res.begin(), res.end(), [](int x, int y) { return x < y; });

	print_arr(std::cout, res) << std::endl;
}
