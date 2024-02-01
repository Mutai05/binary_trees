#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* Base case: If the tree is NULL, it is not full */
	if (tree == NULL)
		return (0);

	/* Check if the tree is a leaf (both children are NULL) */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Check if both subtrees are non-empty and full */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If one subtree is empty and the other is non-empty, it is not full */
	return (0);
}
