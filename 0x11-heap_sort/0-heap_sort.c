#include "sort.h"
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

	if (!array)
		return;

	for (i = (int)size / 2 - 1; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (j = (int)size - 1; j > 0; j--)
	{
		swap(array, size, &array[0], &array[j]);
		heapify(array, size, 0, j);
	}
}
/**
 * heapify - heapify an array
 * @array: array to heapify
 * @size: size of array
 * @index: index of "root" node
 * @sub_size: size of sub_tree
 *
 * Return: nothing
 **/
void heapify(int *array, size_t size, size_t index, size_t sub_size)
{
	int parent = index;
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;

	if (left < (int)sub_size && array[left] > array[parent])
		parent = left;

	if (right < (int)sub_size && array[right] > array[parent])
		parent = right;

	if (parent != (int)index)
	{
		swap(array, size, &array[index], &array[parent]);
		heapify(array, size, parent, sub_size);
	}
}
/**
 * swap - swaps two elements
 * @array: array passed in
 * @size: size of array
 * @parent: parent value
 * @child: child value
 *
 * Return: nothing
 **/
void swap(int *array, size_t size, int *parent, int *child)
{
	int temp;

	temp = *parent;
	*parent = *child;
	*child = temp;

	print_array(array, size);
}
