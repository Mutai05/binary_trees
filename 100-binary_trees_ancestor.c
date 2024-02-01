#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 *         ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	binary_tree_t *ancestor_f, *ancestor_s;

	if (!first || !second)
		return (NULL);

	ancestor_f = (binary_tree_t *)first;
	ancestor_s = (binary_tree_t *)second;

	while (ancestor_f)
	{
		ancestor_s = (binary_tree_t *)second;
		while (ancestor_s)
		{
			if (ancestor_f == ancestor_s)
				return (ancestor_f);
			ancestor_s = ancestor_s->parent;
		}
		ancestor_f = ancestor_f->parent;
	}

	return (NULL);
}
