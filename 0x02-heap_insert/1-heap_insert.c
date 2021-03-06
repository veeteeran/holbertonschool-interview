#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
static size_t _height(const heap_t *tree);

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value stored in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *location;
	int level, height;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}

	height = (int)_height(*root);
	for (level = 0;  level <= height; level++)
	{
		location = finder(*root, level);
		if (!location->right)
			break;
	}

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
 * finder - find parent for new node
 * @root: pointer to the root node of the Heap
 * @level: height of tree
 * Return: pointer to location of insertion, or NULL on failure
 */
heap_t *finder(heap_t *root, int level)
{
	heap_t *location = NULL;

	if (!root)
		return (NULL);

	if (level == 0 || (level == 1 && !root->right))
		return (root);

	location = (finder(root->left, level - 1));

	if (location->right)
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
 * @node: Pointer to the node to measure
 * Return: location of swapped value
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
