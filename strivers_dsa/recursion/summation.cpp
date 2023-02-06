#include <iostream>

int summation(int num) {
	if (num == 0) {
		return 0;
	}

	return num + summation(num - 1);
}

int main(void) {

	std::cout << summation(10) << std::endl;

}
