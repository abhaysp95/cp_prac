#include <iostream>

// You are given a read-only array of N integers with values also in the range
// [1, N] both inclusive. Each integer appears exactly once except A which
// appears twice and B which is missing. The task is to find the repeating and
// missing numbers A and B where A repeats twice and B is missing.

struct arr_wrap {
	int *arr;
	int sz;
};

int *repeating_missing_number(arr_wrap *const my_arr) {
	int *res = (int *)malloc(sizeof(int) * 2);
	int *arr = my_arr->arr;
	int sz = my_arr->sz;

	int ap_sum = (sz * (2 + (sz - 1))) / 2;  // basically, AP sum, but a, d = 1, 1


	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			if (arr[i] == arr[j]) res[0] = arr[i];
		}
	}

	int sum = 0;
	for (int i = 0; i < sz; i++) {
		sum += arr[i];
	}

	res[1] = (ap_sum - sum) + res[0];

	return res;
}

int main(void) {
	// int arr[] = {3,1,2,5,4,6,7,5};
	int arr[] = {3, 1, 2, 4, 3};
	arr_wrap my_arr = {
		.arr = arr,
		.sz = sizeof(arr) / sizeof(int),
	};

	int sz = sizeof(arr) / sizeof(int);

	int *res = repeating_missing_number(&my_arr);
	printf("%d, %d\n", res[0], res[1]);

	free(res);

	return 0;
}
