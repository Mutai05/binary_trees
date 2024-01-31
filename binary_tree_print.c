#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * print_tree - Recursively print a binary tree on console
 * @tree: Pointer to the root node of the tree
 * @space: Number of spaces for indentation
 * @is_left: Flag to check if the current node is the left child
 */
void print_tree(const binary_tree_t *tree, int space, int is_left)
{
    if (tree == NULL)
        return;

    space += 4;

    if (tree->right != NULL)
        print_tree(tree->right, space, 0);

    printf("\n");

    for (int i = 4; i < space; i++)
        printf(" ");

    if (is_left)
        printf(" /");
    else
        printf(" \\");

    printf("-- %d\n", tree->n);

    if (tree->left != NULL)
        print_tree(tree->left, space, 1);
}

/**
 * binary_tree_print - Print a binary tree on console
 * @tree: Pointer to the root node of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    print_tree(tree, 0, 0);
}
