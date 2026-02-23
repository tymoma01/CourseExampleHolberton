#include <stdio.h>
#include "binary_trees.h"

void preorder(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	printf("%d ", tree->n);
	preorder(tree->left);
	preorder(tree->right);
}

void inorder(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	inorder(tree->left);
	printf("%d ", tree->n);
	inorder(tree->right);
}

void postorder(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	postorder(tree->left);
	postorder(tree->right);
	printf("%d ", tree->n);
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
