#ifndef NC_ARRAY_H
#define NC_ARRAY_H

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

void 
int32_arr_print(int32_t *arr, size_t n);

int
int32_arr_set_all_rand(int32_t *arr, size_t n, int32_t upper);

int
int32_arr_sort_selection(int32_t *arr, size_t n);

int 
int32_arr_sort_bubble(int32_t *arr, size_t n);

int
int32_arr_sort_insertion(int32_t *arr, size_t n);

#endif // NVC_ARRAY_H