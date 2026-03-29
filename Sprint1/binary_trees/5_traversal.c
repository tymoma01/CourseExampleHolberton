#include <stdio.h>
#include "binary_trees.h"

/* PREORDER: visit → left → right
 * The root is always printed first.
 * Useful for copying or serializing a tree. */
void preorder(const binary_tree_t *tree)
{
	if (tree == NULL) // base case: empty subtree, nothing to do
		return;

	printf("%d ", tree->n); // VISIT first
	preorder(tree->left); // then recurse left
	preorder(tree->right); // then recurse right
}

/* INORDER: left → visit → right
 * For a BST this always prints values in sorted (ascending) order.
 * That property is what makes BSTs so useful. */
void inorder(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	inorder(tree->left); // recurse left first
	printf("%d ", tree->n); // VISIT in the middle
	inorder(tree->right); // recurse right last
}

/* POSTORDER: left → right → visit
 * Children are always processed before their parent.
 * Useful when you need to free/delete a tree (free children before parent). */
void postorder(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	postorder(tree->left); // recurse left
	postorder(tree->right); // recurse right
	printf("%d ", tree->n); // VISIT last
}

/**
 * build_sample_tree - build this tree:
 *
 *            (10)
 *           /    \
 *         (5)    (20)
 *        /  \    /
 *      (2) (7) (15)
 */
binary_tree_t *build_sample_tree(void)
{
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

	printf("Preorder   (root, left, right):  ");
	preorder(root);
	printf("\n");

	printf("Inorder    (left, root, right):  ");
	inorder(root);
	printf("\n");

	printf("Postorder  (left, right, root):  ");
	postorder(root);
	printf("\n");

	return (0);
}
