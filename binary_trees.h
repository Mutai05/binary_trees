#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Basic Binary Tree Structure */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree Structure */
typedef struct binary_tree_s bst_t;

/* AVL Tree Structure */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap Structure */
typedef struct binary_tree_s heap_t;

/* Function to Print Binary Tree (For Visualization) */
void binary_tree_print(const binary_tree_t *tree);

/* Function to Create a Binary Tree Node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

#endif /* BINARY_TREES_H */
