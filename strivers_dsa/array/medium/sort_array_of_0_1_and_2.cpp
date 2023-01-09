#include <iostream>
#include <vector>

using vec = std::vector<int>;

void print_arr(const vec& arr) {
	for (size_t i{}; i < arr.size() - 1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d\n", arr[arr.size() - 1]);
}

/** first approach */
// follow the algo for making all 0 to end, first move the all 2 to the end, and
// then move all 0 to first
void solution1(vec& arr) {
	// find first 2
	size_t key_to_move = 0;
	for (size_t i{}; i < arr.size(); i++) {
		if(2 == arr[i]) {
			key_to_move = i;
			break;
		}
	}

	// move every 2 to last
	for (size_t i{key_to_move}, j{key_to_move}; i < arr.size(); i++) {
		if (2 != arr[i]) {
			std::swap(arr[i], arr[j]);
			j++;
		}
	}

	// move every 0 to start
	// we'll iteratate array in reverse order and perform same operation as above
	for (size_t i{}; i < arr.size(); i++) {
		if (0 == arr[i]) {
			key_to_move = i;  // find the last 0
		}
	}

	// move 0 to start
	for (size_t i{key_to_move}, j{key_to_move}; i >= 0; i--) {
		if (0 != arr[i]) {
			std::swap(arr[i], arr[j]);
			j--;
		}

		if (0 == i) break;
	}
}

// solution 2 is to count 0, 1 and 2 frequency. and then put 0, 1 and 2 into the
// array as per their frequency

// dutch national flag algo (also known as 3 pointer approach)
void solution2(vec& arr) {
	if (0 == arr.size()
			|| 1 == arr.size()) return;

	size_t low{}, mid{}, high{arr.size() - 1};

	while (mid <= high) {
		if (arr[mid] == 0) {  // move the 0 to start
			std::swap(arr[low], arr[mid]);
			low++, mid++;
		} else if (arr[mid] == 1) {
			mid++;
		} else {  // move the 2 to end
			std::swap(arr[mid], arr[high]);
			high--;
		}
	}

}

int main(void) {
	vec arr {2, 0, 2, 1, 1, 0};

	// solution1(arr);
	solution2(arr);

	print_arr(arr);

	return 0;
}
