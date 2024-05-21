#include "array.h"

void 
int32_arr_print(int32_t *arr, size_t n) {
	printf("[ ");

	for (size_t i = 0; i < n; i++) {
		printf("%" PRId32 , arr[i]);
		if (n != 0 && i != n - 1) {
			printf(", ");
		}
	}

	printf(" ]\n");
	return;
}

int
int32_arr_set_all_rand(int32_t *arr, size_t n, int32_t upper) {
	srand(time(NULL));

	for (size_t i = 0; i < n; i++) {
		arr[i] = rand() % upper;
	}

	return 0;
}