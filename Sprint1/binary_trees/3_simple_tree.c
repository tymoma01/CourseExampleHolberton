#include <stdio.h>
#include "binary_trees.h"

/* Simple inorder print to visualize */
void inorder(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	printf("%d ", tree->n);
	inorder(tree->right);
}

/* FOR:
         (10)
        /    \
      (5)    (15)
    start: inorder(tree = 10)
    inoder(tree = 5)
    inorder(tree = NULL) -> return
    we go back up so that tree = 5
    then:
    print 5
    we go back up so that tree = 10
    print 10
    Then inorder(tree->right) where tree->right = 15
    inorder 15
    inorder(NULL) -> return
    print 15
*/



/**
 * main - build a small hand-made tree
 *
 *        (10)
 *       /    \
 *     (5)    (15)
 *
 * Return: Always 0
 */
int main(void)
{
	binary_tree_t *root;
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	root = binary_tree_node(NULL, 10);
	left_child = binary_tree_node(root, 5);
	right_child = binary_tree_node(root, 15);

	/* Connect children */
	root->left = left_child;
	root->right = right_child;

	printf("Root value: %d\n", root->n);
	printf("Left child: %d (parent %d)\n", left_child->n, left_child->parent->n);
	printf("Right child: %d (parent %d)\n", right_child->n, right_child->parent->n);
	printf("Inorder traversal: ");
	inorder(root);
	printf("\n");

	return (0);
}
