#include <iostream>

void print_array(int *arr, int sz);

// remove duplicate elements from sorted array

struct arr_struct {
	int *arr;
	int sz;
};

void remove_sorted(arr_struct *const my_arr) {
	int *arr = my_arr->arr;
	int sz = my_arr->sz;
	int i = 0, j = 0;

	// below if-else can be simplified to just use one if though
	while (i < sz) {
		if (i < sz - 1 && arr[i] == arr[i + 1]) {
			i++;
		} else {
			arr[j] = arr[i];
			j++, i++;
		}
	}

	my_arr->sz = j;  // update new size
}

void print_array(arr_struct *const my_arr) {
	if (0 == my_arr->sz) return;

	for (int i = 0; i < my_arr->sz - 1; i++) {
		printf("%d, ", my_arr->arr[i]);
	}
	printf("%d\n", my_arr->arr[my_arr->sz - 1]);
}

int main(void) {
	int arr[] = {1,2,3,4,4,5,6,6,6,7};
	// int arr[] = {1,1,2,2,2,3,3};
	int sz = sizeof(arr) / sizeof(int);
	struct arr_struct my_arr = {
		.arr = arr,
		.sz = sz
	};

	remove_sorted(&my_arr);
	print_array(&my_arr);

	return 0;
}
