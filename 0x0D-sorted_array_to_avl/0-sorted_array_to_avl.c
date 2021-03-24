#include "binary_trees.h"

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

        if (!array)
                return (NULL); 

        create_tree(tree, array, size - 1);
    
        return (tree);
}
    
avl_t *create_tree(avl_t *tree, int *array, size_t size)
{
        size_t mid = size / 2;

        printf("size: %d\n", (int)size);
        if (size == 0)
        {
                tree->left = node_maker(array[mid]);
                printf("tree->left: %d\n", tree->left->n);
                return (tree);
        }

	tree->left = create_tree(tree, array, mid - 1);
	tree->right = create_tree(tree, array, mid + 1);

	return (tree);
}

avl_t *node_maker(int n)
{
        avl_t *node;

        node = malloc(sizeof(avl_t));
        if (!node)
                return (NULL);

        node->parent = NULL;
        node->n = n;
        node->left = NULL;
        node->right = NULL;

        return (node);
}
