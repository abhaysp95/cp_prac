#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

size_t total_time_taken(const vector<size_t>& pps, size_t N) {
	size_t tt{0};
	size_t c1 = N, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

	while (c5 != N) {
		size_t ntoc5 = min(c4, pps[3]);
		c5 += ntoc5;
		c4 -= ntoc5;
		size_t ntoc4 = min(c3, pps[2]);
		c4 += ntoc4;
		c3 -= ntoc4;
		size_t ntoc3 = min(c2, pps[1]);
		c3 += ntoc3;
		c2 -= ntoc3;
		size_t ntoc2 = min(c1, pps[0]);
		c2 += ntoc2;
		c1 -= ntoc2;
		tt++;
	}

	return tt;
}

int main(void) {
	size_t N{};
	cin >> N;

	vector<size_t> pps{};
	string temp{};
	while (getline(cin, temp, ' ')) {
		pps.push_back(stoi(temp));
	}

	cout << total_time_taken(pps, N);

	return 0;
}
