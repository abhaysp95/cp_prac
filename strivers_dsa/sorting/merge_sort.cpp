#include <iostream>

using namespace std;

void merge_sort(int* arr, int start, int end);
void merge(int* arr, int start, int half, int end);

int main(void) {
	int arr[] = {3, 1, 2, 4, 1, 5, 2, 6, 4};
	int size = sizeof(arr) / sizeof(int);

	merge_sort(arr, 0, size - 1); // both start and end are inclusive

	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}

void merge_sort(int* arr, int start, int end) {
	// base case
	if (start == end) return;

	// induction
	int half = (start + end) / 2;

	// hypothesis
	merge_sort(arr, start, half);
	merge_sort(arr, half + 1, end);

	// induction
	merge(arr, start, half, end);
}

void merge(int* arr, int start, int half, int end) {
	int size = end - start + 1;
	printf("start: %d, half: %d, end: %d\n", start, half, end);
	int temp_arr[size];

	int i = start, j = half + 1;
	int k = 0;
	while (i <= half && j <= end) {
		// temp_arr[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
		if (arr[i] < arr[j]) {
			temp_arr[k] = arr[i];
			i++;
		} else {
			temp_arr[k] = arr[j];
			j++;
		}
		k++;
	}

	// fill rest of the array
	while (i <= half) {
		temp_arr[k] = arr[i];
		i++, k++;
	}
	while (j <= end) {
		temp_arr[k] = arr[j];
		j++, k++;
	}

	cout << "temp array:\n";
	for (int i = 0; i < size; i++) {
		cout << temp_arr[i] << ' ';
	}
	cout << '\n';

	// update the original array
	for (int i = 0, j = start; j <= end; i++, j++) {
		arr[j] = temp_arr[i];
	}
}
