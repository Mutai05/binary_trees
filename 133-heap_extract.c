#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heapify_down - Move the node down the heap to restore max heap property
 * @root: A pointer to the root node
 *
 * Return: The new root of the heap
 */
heap_t *heapify_down(heap_t *root)
{
	heap_t *largest, *temp;

	while (1)
	{
		largest = root;

		if (root->left && root->left->n > largest->n)
			largest = root->left;

		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temp = root->parent;
		if (root->parent)
		{
			if (root->parent->left == root)
				root->parent->left = largest;
			else
				root->parent->right = largest;
		}
		if (largest->left)
			largest->left->parent = root;

		if (largest->right)
			largest->right->parent = root;

		if (temp)
		{
			largest->parent = temp;
			if (temp->left == root)
				temp->left = largest;
			else
				temp->right = largest;
		}
		else
		{
			largest->parent = NULL;
			return (largest);
		}

		root->parent = largest;

		temp = largest->left;
		largest->left = root->left;
		root->left = temp;

		temp = largest->right;
		largest->right = root->right;
		root->right = temp;
	}

	return (largest);
}

/**
 * get_last_node - Get the last node in the heap
 * @root: A pointer to the root node
 *
 * Return: The last node
 */
heap_t *get_last_node(heap_t *root)
{
	size_t size, mask;

	size = tree_size(root);
	mask = 1;
	while (mask <= size)
		mask <<= 1;

	mask >>= 2;

	while (mask > 0)
	{
		if (size & mask)
			root = root->right;
		else
			root = root->left;

		mask >>= 1;
	}

	return (root);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: A double pointer to the root node of heap
 *
 * Return: The value stored in the root node or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *extracted_node;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;

	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(*root);

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	extracted_node = *root;
	*root = last_node;

	if (extracted_node->left)
		extracted_node->left->parent = *root;

	if (extracted_node->right)
		extracted_node->right->parent = *root;

	(*root)->parent = NULL;

	*root = heapify_down(*root);

	free(extracted_node);

	return (value);
}
