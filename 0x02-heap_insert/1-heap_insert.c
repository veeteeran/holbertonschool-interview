#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
heap_t *finder(heap_t *root);

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value stored in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *location;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}

	location = finder(*root);

	new = binary_tree_node(location, value);
	if (!new)
                return (NULL);

	new->parent = location;
	if (!location->left)
		location->left = new;
	else
		location->right = new;

	return (new);
}

/**
 * finder: find parent for new node
 * @root: pointer to the root node of the Heap
 * Return: pointer to location of insertion, or NULL on failure
 */
heap_t *finder(heap_t *root) {
	heap_t *location;

	if (!root)
		return (NULL);

	location = root;
/*	if (location->parent)
		printf("location->parent->n: %d\n", location->parent->n);
*/	printf("visited: %d\n", location->n);
	printf("location: %p\n", (void*)location);

	if (!location->right)
		return (location);

	if (location->left)
		return (finder(location->left));

	return (finder(location->right));
}
