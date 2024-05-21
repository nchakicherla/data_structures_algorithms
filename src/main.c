#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <inttypes.h>
#include <stdint.h>
#include <time.h>

#include "nc_array.h"

#define ARR_SIZE			50000

int main(void) {
	int32_t *arr = calloc(ARR_SIZE, sizeof(int32_t));


	int32_arr_set_all_rand(arr, ARR_SIZE, 999);
	//int32_arr_print(arr, ARR_SIZE);
	

	printf("\n\nselection sorting...\n");
	//int32_arr_print(arr, ARR_SIZE);
	clock_t time_req = clock();
	int32_arr_sort_selection(arr, ARR_SIZE);
	time_req = clock() - time_req;
	
	//int32_arr_print(arr, ARR_SIZE);
	printf("selection sorting took %f - seconds\n\n", (float)time_req / CLOCKS_PER_SEC);

	int32_arr_set_all_rand(arr, ARR_SIZE, 999);
	printf("new rand array...\n");
	//int32_arr_print(arr, ARR_SIZE);


	printf("\n\nbubble sorting...\n");

	time_req = clock();
	int32_arr_sort_bubble(arr, ARR_SIZE);
	time_req = clock() - time_req;

	//int32_arr_print(arr, ARR_SIZE);
	printf("bubble sorting took %f - seconds\n\n", (float)time_req / CLOCKS_PER_SEC);
	

	int32_arr_set_all_rand(arr, ARR_SIZE, 999);
	printf("new rand array...\n");
	//int32_arr_print(arr, ARR_SIZE);


	printf("\n\ninsertion sorting...\n");

	time_req = clock();
	int32_arr_sort_insertion(arr, ARR_SIZE);
	time_req = clock() - time_req;

	//int32_arr_print(arr, ARR_SIZE);
	printf("insertion sorting took %f - seconds\n\n", (float)time_req / CLOCKS_PER_SEC);

	int32_arr_set_all_rand(arr, ARR_SIZE, 999);
	printf("new rand array...\n");
	//int32_arr_print(arr, ARR_SIZE);


	printf("\n\nmerge sorting...\n");

	time_req = clock();
	int32_arr_sort_merge(arr, ARR_SIZE);
	time_req = clock() - time_req;

	//int32_arr_print(arr, ARR_SIZE);
	printf("merge sorting took %f - seconds\n\n", (float)time_req / CLOCKS_PER_SEC);

	int32_arr_set_all_rand(arr, ARR_SIZE, 999);
	printf("new rand array...\n");
	//int32_arr_print(arr, ARR_SIZE);


	printf("\n\nquick sorting...\n");

	time_req = clock();
	int32_arr_sort_quick(arr, ARR_SIZE);
	time_req = clock() - time_req;

	//int32_arr_print(arr, ARR_SIZE);
	printf("quick sorting took %f - seconds\n\n", (float)time_req / CLOCKS_PER_SEC);


	free(arr);
	return 0;
}