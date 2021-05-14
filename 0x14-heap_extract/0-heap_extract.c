#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heapi
 *
 * Return: value stored in the root node, 0 on failure
 **/

int heap_extract(heap_t **root)
{
	return ((*root)->n);
}
