#include "nc_array.h"

bool RAND_SEEDED = false;

void
__swap_int32_ptr_vals(int32_t *ptr1, int32_t *ptr2) {
	int32_t tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
	return;
}

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

	if (!RAND_SEEDED) {
		srand(time(NULL));
		RAND_SEEDED = true;
	}

	for (size_t i = 0; i < n; i++) {
		arr[i] = rand() % upper;
	}

	return 0;
}

int
int32_arr_sort_selection(int32_t *arr, size_t n) {

	for (size_t i = 0; i < n; i++) {

		//int32_t min = arr[i];
		size_t min_idx = i;

		//*int32

		//int32_arr_print(arr, n);
		for (size_t j = i; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				//min = arr[j];
				min_idx = j;
			}
		}
		if (min_idx != i) {
			__swap_int32_ptr_vals(&arr[i], &arr[min_idx]);
		}
	}

	return 0;
}

int 
int32_arr_sort_bubble(int32_t *arr, size_t n) {

	if (n <= 1) {
		return 0;
	}

	for (size_t i = 0; i < n; i++) {

		//int32_arr_print(arr, n);
		for (size_t j = 1; j < n - i; j++) {
			if (arr[j - 1] > arr[j]) {
				__swap_int32_ptr_vals(&arr[j - 1], &arr[j]);
			}
		}
	}

	return 0;
}

int
int32_arr_sort_insertion(int32_t *arr, size_t n) {

	if (n <= 1) {
		return 0;
	}

	for (size_t i = 1; i < n; i++) {

		//int32_arr_print(arr, n);
		int32_t key = arr[i];
		size_t j = i - 1;

		while (j != SIZE_MAX && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	//int32_arr_print(arr, n);
	return 0;
}

int
int32_arr_sort_merge(int32_t *arr, size_t n) {

	if (n <= 1) {
		return 0;
	}

	size_t lh_n = n / 2;
	size_t rh_n = n - lh_n;

	int32_t *lh_arr = calloc(lh_n, sizeof (int32_t));
	int32_t *rh_arr = calloc(rh_n, sizeof (int32_t));

	for (size_t i = 0; i < lh_n; i++) {
		lh_arr[i] = arr[i];
	}

	size_t j = 0;
	for (size_t i = lh_n; i < n; i++) {
		rh_arr[j] = arr[i];
		j++;
	}

/*
	printf("left: ");
	int32_arr_print(lh_arr, lh_n);
	printf("right: ");
	int32_arr_print(rh_arr, lh_n);
*/
	int32_arr_sort_merge(lh_arr, lh_n);

	int32_arr_sort_merge(rh_arr, rh_n);

	size_t ii = 0;
	size_t jj = 0;
	size_t kk = 0;

	while (ii < lh_n && jj < rh_n) {
		if (lh_arr[ii] < rh_arr[jj]) {
			arr[kk] = lh_arr[ii];
			ii++;
		} else {
			arr[kk] = rh_arr[jj];
			jj++;
		}
		kk++;
	}

	while (ii < lh_n) {
		arr[kk] = lh_arr[ii];
		ii++;
		kk++;
	}

	while (jj < rh_n) {
		arr[kk] = rh_arr[jj];
		jj++;
		kk++;
	}

	free(lh_arr);
	free(rh_arr);
	return 0;
}

int
int32_arr_sort_quick(int32_t *arr, size_t n) {

	if (n <= 1) {
		return 0;
	}

	size_t pivot_idx = SIZE_MAX;
	int32_t pivot = arr[n - 1];

	for (size_t j = 0; j < n; j++) {
		if (arr[j] < pivot) {
			pivot_idx++;
			__swap_int32_ptr_vals(&arr[j], &arr[pivot_idx]);
		}
	}
	pivot_idx++;
	__swap_int32_ptr_vals(&arr[pivot_idx], &arr[n - 1]);

	int32_arr_sort_quick(arr, pivot_idx); // sort left of pivot
	int32_arr_sort_quick(&arr[pivot_idx+1], n - pivot_idx - 1); // sort right of pivot

	return 0;
}
