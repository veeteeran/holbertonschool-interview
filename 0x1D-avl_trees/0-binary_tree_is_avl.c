#include "binary_trees.h"
int _height(const binary_tree_t *tree);
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 **/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_l = 0, height_r = 0, diff = 0;

	if (!tree)
		return (0);

	height_l = _height(tree->left);
	height_r = _height(tree->right);
	diff = height_l > height_r ? height_l - height_r : height_r - height_l;
	if (diff <= 1 && binary_tree_is_avl(tree->left)
		&& binary_tree_is_avl(tree->right))
		return (0);
	return (1);
}
/**
 * _height - function to check height of ree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: height of tree
 **/
int _height(const binary_tree_t *tree)
{
	int height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	height_left =  _height(tree->left);
	height_right = _height(tree->right);

	if (height_left > height_right)
		return (1 + height_left);
	else
		return (1 + height_right);
}
