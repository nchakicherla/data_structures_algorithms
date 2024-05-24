#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <inttypes.h>
#include <stdint.h>
#include <time.h>

#include "nc_array.h"

#define ARR_SIZE			100000

int (*int32_arr_sort_fns[10])(int32_t *, size_t);

void
TESTS_int32_arr_sort(int32_t *arr, size_t len, int32_t upper) {

	int32_arr_sort_fns[0] = int32_arr_sort_selection;
	int32_arr_sort_fns[1] = int32_arr_sort_bubble;
	int32_arr_sort_fns[2] = int32_arr_sort_insertion;
	int32_arr_sort_fns[3] = int32_arr_sort_merge;
	int32_arr_sort_fns[4] = int32_arr_sort_quick;

	clock_t time_taken = clock();

	for (int i = 0; i < 5; i++) {
		
		time_taken = clock();
		int32_arr_set_all_rand(arr, len, upper);

		int ret = (*int32_arr_sort_fns[i])(arr, len);
		time_taken = clock() - time_taken;

		printf("i: %d\tret: %d\ttime: %f\n", i + 1, ret, (float)time_taken / CLOCKS_PER_SEC);
	}

	return;
}

int main(void) {

	int32_t *arr = calloc(ARR_SIZE, sizeof(int32_t));

	TESTS_int32_arr_sort(arr, ARR_SIZE, 999);

	free(arr);
	return 0;
}