#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <inttypes.h>
#include <stdint.h>

#include "array.h"

#define ARR_SIZE			100

int main(void) {

	int32_t *arr = calloc(ARR_SIZE, sizeof(int32_t));
	int32_arr_set_all_rand(arr, ARR_SIZE, 999);
	int32_arr_print(arr, ARR_SIZE);
	free(arr);

	return 0;
}