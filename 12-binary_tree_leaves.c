#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: Number of leaves in the tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* Base case: If the tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Check if the current node is a leaf (both left and right are NULL) */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively count the leaves in the left and right subtrees */
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
