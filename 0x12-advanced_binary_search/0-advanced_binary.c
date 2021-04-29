#include "search_algos.h"
int helper(int *array, int start, int end, int value);
/**
 * advanced_binary_search - searches for a value in a sorted array of
 * integers using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	int start = 0, end = size - 1;

	if (array == NULL)
                return (-1);

	return helper(array, start, end, value);
}

int helper(int *array, int start, int end, int value)
{
	int mid, i;

	if (end >= start)
	{
		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i < end)
				printf(", ");
		}
		printf("\n");

		mid = start + (end - start) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);

		if (array[mid] >= value)
			return helper(array, start, mid, value);

		return helper(array, mid + 1, end, value);
	}

	return (-1);
}
