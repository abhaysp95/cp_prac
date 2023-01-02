#include <iostream>

void print_array(int *, int);

// left rotate array by k place
// using extra space
void left_rotate_extra_space(int *arr, int sz, int times) {

	int k = times % sz;
	int *temp = (int *)malloc(sizeof(int) * k);

	for (int i = (sz - k); i < sz; i++) {
		temp[i - (sz - k)] = arr[i];
	}
	printf("==> ");
	print_array(temp, k);

	for (int i = 0; i < k; i++) {
		arr[sz - k + i] = arr[i];
		arr[i] = temp[i];
	}
}

// left rotate array by one place
void left_rotate_one(int *arr, int sz) {
	int first = arr[0];
	arr[0] = first;
	arr[sz - 1] = first;
}

void print_array(int *arr, int sz) {
	if (0 == sz) return;
	for (int i = 0; i < sz - 1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d\n", arr[sz - 1]);
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int sz = sizeof(arr) / sizeof(int);
	int times = 0;
	scanf("%d", &times);
	left_rotate_extra_space(arr, sz, times);
	print_array(arr, sz);

	return 0;
}
