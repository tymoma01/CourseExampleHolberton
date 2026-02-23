#include <stdio.h>
#include "binary_trees.h"

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (node->left == NULL && node->right == NULL);
}

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/* height in “edges”, so a single node has height 0, NULL = -1 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return ((size_t)-1);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

binary_tree_t *build_sample_tree(void)
{
    /*
        (10)
        /  \
      (5)   (20)
      / \    / 
    (2) (7) (15)
      */
	binary_tree_t *root = binary_tree_node(NULL, 10);

	root->left = binary_tree_node(root, 5);
	root->right = binary_tree_node(root, 20);

	root->left->left = binary_tree_node(root->left, 2);
	root->left->right = binary_tree_node(root->left, 7);

	root->right->left = binary_tree_node(root->right, 15);

	return (root);
}

int main(void)
{
	binary_tree_t *root = build_sample_tree();

	printf("Tree size (number of nodes): %lu\n",
	       (unsigned long)binary_tree_size(root));
	printf("Tree height (in edges):      %lu\n",
	       (unsigned long)binary_tree_height(root));
	printf("Is root a leaf? %s\n",
	       binary_tree_is_leaf(root) ? "yes" : "no");
	printf("Is root->left->left (%d) a leaf? %s\n",
	       root->left->left->n,
	       binary_tree_is_leaf(root->left->left) ? "yes" : "no");
    printf("Is root->left->right (%d) a leaf? %s\n",
	       root->left->left->n,
	       binary_tree_is_leaf(root->left->right) ? "yes" : "no");
    printf("Is root->right->left (%d) a leaf? %s\n",
            root->left->left->n,
            binary_tree_is_leaf(root->right->left) ? "yes" : "no");
    printf("Is root->right->right (%d) a leaf? %s\n",
            root->left->left->n,
            binary_tree_is_leaf(root->right->right) ? "yes" : "no");
	return (0);
}
