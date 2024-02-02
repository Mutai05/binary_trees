#include "binary_trees.h"

/* Prototype of the helper function */
avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end, avl_t *parent);

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == 0 || !array)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}

/**
 * sorted_array_to_avl_helper - recursive helper function
 * @array: pointer to the first element of the array
 * @start: starting index of the current subtree in the array
 * @end: ending index of the current subtree in the array
 * @parent: pointer to the parent node
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *new_node;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new_node = binary_tree_node(parent, array[mid]);
	if (!new_node)
		return (NULL);

	new_node->left = sorted_array_to_avl_helper(array, start, mid - 1, new_node);
	new_node->right = sorted_array_to_avl_helper(array, mid + 1, end, new_node);

	return (new_node);
}
