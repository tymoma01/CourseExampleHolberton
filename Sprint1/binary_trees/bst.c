#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Insert respecting BST rule:
 * left subtree < node, right subtree > node
 * (no duplicates for simplicity)
 */
binary_tree_t *bst_insert(binary_tree_t **root, int value)
{
	binary_tree_t *parent = NULL;
	binary_tree_t *current = *root;
	binary_tree_t *new_node;

	while (current != NULL)
	{
		parent = current;
		if (value < current->n)
        {
            current = current->left;
        }
		else if (value > current->n)
        {
            current = current->right;
        }
		else
			return (current);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
    {
        return (NULL);
    }
	

	if (parent == NULL)
    {
        *root = new_node;
    }
	else if (value < parent->n)
    {
        parent->left = new_node;
    }
	else
    {
        parent->right = new_node;
    }
	return (new_node);
}

binary_tree_t *bst_search(binary_tree_t *root, int value)
{
	while (root != NULL)
	{
		if (value == root->n)
			return (root);
		if (value < root->n)
			root = root->left;
		else
			root = root->right;
	}
	return (NULL);
}

void inorder(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	inorder(tree->left);
	printf("%d ", tree->n);
	inorder(tree->right);
}

int main(void)
{
	int i;
	int values[] = { 27, 14, 35, 10, 19, 31, 42 };
	binary_tree_t *root = NULL;
	binary_tree_t *found;

	for (i = 0; i < 7; i++) 
    {
		bst_insert(&root, values[i]);
        binary_tree_print_pretty(root);
        printf("-------------------------------------------------\n");
    }

	printf("Inorder traversal of BST (should be sorted):\n");
	inorder(root);
	printf("\n");

	found = bst_search(root, 19);
	printf("Search 19: %s\n", found ? "found" : "not found");

	found = bst_search(root, 100);
	printf("Search 100: %s\n", found ? "found" : "not found");

	return (0);
}
