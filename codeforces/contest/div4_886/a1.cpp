#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x + y >= 10 || x + z >= 10 || y + z >= 10) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}

	}

	return 0;
}
