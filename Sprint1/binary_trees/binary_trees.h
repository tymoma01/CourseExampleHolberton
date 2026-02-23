#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Prototypes for examples */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void preorder(const binary_tree_t *tree);
void inorder(const binary_tree_t *tree);
void postorder(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
binary_tree_t *bst_insert(binary_tree_t **root, int value);
binary_tree_t *bst_search(binary_tree_t *root, int value);
void binary_tree_print_pretty(const binary_tree_t *tree);

#endif
