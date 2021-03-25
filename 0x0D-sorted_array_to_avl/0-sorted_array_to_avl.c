#include "binary_trees.h"
void binary_tree_delete(avl_t **tree);
/**       
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *       
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{     
        avl_t *tree = NULL;
	int flag = 1;

        if (!array)
                return (NULL); 

        create_tree(&tree, array, size, flag);
    
        return (tree);
}

/**
 * create_tree - creates an AVL tree
 * @tree: pointer to the tree 
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * @flag: determines whether recursion goes left or right
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 **/
avl_t *create_tree(avl_t **tree, int *array, size_t size, int flag)
{            
        size_t mid = (size - 1) / 2;
        avl_t *node = node_maker(array[mid]);

	if (!node)
	{
		binary_tree_delete(tree);
		return (NULL);
	}

        if (size == 0)
                return (*tree);

        node->parent = *tree;

        if (!*tree)
                *tree = node;
        else if (flag == 1)
                (*tree)->left = node;
        else
                (*tree)->right = node;

        create_tree(&node, array, mid, 1);
        create_tree(&node, &array[mid + 1], size - (mid + 1), 0);

        return (*tree);
}

/*
 * node_maker - creates a node to an AVL tree
 * @n: data contained in node
 *
 * Return: node or NULL on failure
 **/
avl_t *node_maker(int n)
{
        avl_t *node;

        node = malloc(sizeof(avl_t));
        if (!node)
                return (NULL);

        node->n = n;
        node->parent = NULL;
        node->left = NULL;
        node->right = NULL;

        return (node);
}

/**
 * binary_tree_delete - removes an entire binary tree
 * @tree: pointer to the root node of the tree to remove
 *
 */
void binary_tree_delete(avl_t **tree)
{
	if (tree == NULL)
		return;

	if (tree->left)
		binary_tree_delete(tree->left);
	if (tree->right)
		binary_tree_delete(tree->right);
	free(tree);
	/* tree = NULL */
}
