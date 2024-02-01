#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    /* Base case: If the tree or the function is NULL, do nothing */
    if (tree == NULL || func == NULL)
        return;

    /* Recursively traverse the left subtree */
    binary_tree_postorder(tree->left, func);

    /* Recursively traverse the right subtree */
    binary_tree_postorder(tree->right, func);

    /* Call the function for the current node */
    func(tree->n);
}
