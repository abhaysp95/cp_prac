#include <iostream>

struct arrwrap {
	int *arr;
	int sz;
};

void swap(int *arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void print_arr(arrwrap *const my_arr) {
	if (0 == my_arr->sz) return;
	for (int i = 0; i < my_arr->sz - 1; i++) {
		printf("%d, ", my_arr->arr[i]);
	}

	printf("%d\n", my_arr->arr[my_arr->sz - 1]);
}

void move_zeroes_to_end(arrwrap *my_arr) {
	int *arr = my_arr->arr;
	int sz = my_arr->sz;
	if (0 == sz
			|| 1 == sz) return;

	// get first occurence of 0
	int k = 0;
	while (k < sz) {
		if (0 == arr[k]) {
			break;
		}
		k++;
	}

	int i = k, j = i + 1;
	while (i < sz && j < sz) {
		if (0 != arr[j]) {
			swap(arr, i, j);
			i++;
		}
		j++;
	}

}


int main(void) {
	int arr[] = {1, 2, 0, 1, 0, 4, 0};
	arrwrap my_arr = {
		.arr = arr,
		.sz = sizeof(arr) / sizeof(int),
	};

	move_zeroes_to_end(&my_arr);
	print_arr(&my_arr);

	return 0;
}
