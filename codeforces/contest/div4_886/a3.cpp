#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		string str{};
		char ch;
		int col = -1;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> ch;
				if (ch != '.')  {
					if (col == -1 || col == j) {
						if (col == -1) col = j;
						str += ch;
					}
				}
			}
		}

		cout << str << '\n';
	}

	return 0;
}
