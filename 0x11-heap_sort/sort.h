#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t index, size_t sub_size);
void swap(int *array, size_t size, int *parent, int *child);
void print_array(const int *array, size_t size);
#endif /* _SORT_H_ */
