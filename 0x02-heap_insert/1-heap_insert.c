#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
heap_t *finder(heap_t *root, size_t level);
static size_t _height(const heap_t *tree);
heap_t *heapify(heap_t *node);

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value stored in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *location;
	size_t index;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}

	index = _height(*root);
	location = *root;
	for (; (int)index > 0; index--)
	{
	/*	printf("In loop: index: %lu\n", index);
        */	location = finder(location, index);
/*		printf("In loop: location->n: %d\n", location->n);
*/	}
/*	printf("outside loop: location->n: %d\n", location->n);
*/
	new = binary_tree_node(location, value);
	if (!new)
                return (NULL);

	if (!location->left)
		location->left = new;
	else
		location->right = new;

	new = heapify(new);

	return (new);
}

/**
 * finder: find parent for new node
 * @root: pointer to the root node of the Heap
 * Return: pointer to location of insertion, or NULL on failure
 */
heap_t *finder(heap_t *root, size_t level) {
	heap_t *location = NULL;

	if (!root)
		return (NULL);

/*	location = root;
*/	if (level <= 1 && !root->right)
	{
/*		printf("base case\n");
*/		return (root);
	}

/*	printf("Inside finder: level: %lu\n", level);
	printf("root->n: %d\n", root->n);
*/        location = (finder(root->left, level - 1));
/*        printf("below left side: location->n: %d\n", location->n);
	printf("above right side: level: %lu\n", level);
	printf("above right side: root->n: %d\n", root->n);
*/	if (location->left && location->right)
		location = (finder(root->right, level - 1));

	return (location);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const heap_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * heapify - bubble up so node value >= children
 *
 * @node: Pointer to the node to measure
 *
 */
heap_t *heapify(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}
