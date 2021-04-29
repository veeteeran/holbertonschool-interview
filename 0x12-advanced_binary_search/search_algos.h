#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int advanced_binary(int *array, size_t size, int value);
int helper(int *array, int start, int end, int value);

#endif /* SEARCH_ALGOS_H */
