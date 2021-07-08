#include "sort.h"

/**
 * radix_sort - sorts array of ints, ascending order using Radix sort
 * @array: array to sort
 * @size: size of array
 *
 * Return: Void
 **/

void radix_sort(int *array, size_t size)
{
	int max = get_max(array, (int)size);
	int place;

	if (!array || size < 2)
		return;

	for (place = 1; max / place > 0; place *= 10)
	{
		counting_sort(array, (int)size, place);
		print_array(array, size);
	}
}

/**
 * get_max - get largest element of an array
 * @array: array to sort
 * @size: size of array
 *
 * Return: largest element in array
 **/
int get_max(int *array, int size)
{
	int i, max;

	if (!array)
		return (-1);

	max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sort by significant digits
 * @array: array to sort
 * @size: size of array
 * @place: decimal places
 *
 * Return: Void
 **/
void counting_sort(int *array, int size, int place)
{
	int *output, *count, i;
	int max = (array[0] / place) % 10;

	output = malloc(sizeof(int) * (size + 1));
	if (!output)
		return;
	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i < max; ++i)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
