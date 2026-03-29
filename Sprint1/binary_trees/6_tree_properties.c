#include <stdio.h>
#include "binary_trees.h"

// gcc 6_tree_properties.c 2_node.c

// A leaf has no children — it is a “dead end” in the tree
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (node->left == NULL && node->right == NULL);
}

/* Size = total number of nodes in the tree.
 * Idea: the size of a tree is 1 (this node) + size of left subtree + size of right subtree.
 * The recursion bottoms out when it hits a NULL (empty subtree → 0 nodes). */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) +  // count all nodes on the left
		binary_tree_size(tree->right) + 1); // count all nodes on the right, +1 for this node
}

/* Height = number of edges on the longest path from this node down to a leaf.
 * A single node has height 0.  A NULL pointer returns -1 so that the +1
 * below brings a leaf back to 0 correctly. */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return ((size_t)-1); // sentinel: -1 so that leaf height works out to 0

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	/* Take the taller subtree, then add 1 for the edge connecting this node to it. */
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
