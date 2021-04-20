#include "sort.h"
void swap(int *array, int *parent, int *child);
/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array of ints
 * @size: size of array
 *
 * Return: nothing
 **/
void heap_sort(int *array, size_t size)
{
	int i, j;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (j = (int)size - 1; j >= 0; j--)
	{
		swap(array, &array[0], &array[j]);
		heapify(array, j, 0);
	}
}
/**
 * heapify - heapify an array
 * @array: array to heapify
 * @size: size of array
 * @index: index of "root" node
 *
 * Return: nothing
 **/
void heapify(int *array, size_t size, size_t index)
{
	int parent = index;
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;

	if (left < (int)size && array[left] > array[parent])
		parent = left;

	if (right < (int)size && array[right] > array[parent])
		parent = right;

	if (parent != (int)index)
	{
		swap(array, &array[index], &array[parent]);
		heapify(array, size, parent);
	}
}
/**
 * swap - swaps two elements
 * @parent: parent value
 * @child: child value
 *
 * Return: nothing
 **/
void swap(int *array, int *parent, int *child)
{
	int temp;
	size_t i;

	temp = *parent;
	*parent = *child;
	*child = temp;

	for (i = 0; array[i]; i++)
		continue;

	print_array(array, i);
}
