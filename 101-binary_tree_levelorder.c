#include "binary_trees.h"
#include "stddef.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t *queue[10000] = {0};
    int front = 0, rear = 0;
    const binary_tree_t *current = NULL;

    if (!tree || !func)
        return;

    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        current = queue[front++];

        if (current->left)
            queue[rear++] = (binary_tree_t *)current->left;

        if (current->right)
            queue[rear++] = (binary_tree_t *)current->right;

        func(current->n);
    }
}
