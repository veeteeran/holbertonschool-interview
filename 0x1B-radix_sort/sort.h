#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
void counting_sort(int *array, int size, int place);

#endif /* _SORT_H_ */
