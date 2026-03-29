#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Insert respecting BST rule:
 * left subtree < node, right subtree > node
 * (no duplicates for simplicity)
 *
 * We use TWO pointers that walk down together:
 *   current — the node we are examining right now
 *   parent  — the node just above current (one step behind)
 *
 * When current falls off the tree (NULL) we have found the insertion spot,
 * and parent is the node that the new node should be attached to.
 */
binary_tree_t *bst_insert(binary_tree_t **root, int value)
{
	binary_tree_t *parent = NULL;   // will track the last non-NULL node we visited
	binary_tree_t *current = *root; // starts at the root and walks down
	binary_tree_t *new_node;

	while (current != NULL)
	{
		parent = current;           // remember where we are before stepping down
		if (value < current->n)
        {
            current = current->left;  // go left: value belongs in left subtree
        }
		else if (value > current->n)
        {
            current = current->right; // go right: value belongs in right subtree
        }
		else
			return (current);         // duplicate: value already in tree, do nothing
	}
	/* current == NULL: we found the empty slot where the new node goes */

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
    {
        return (NULL);
    }

	if (parent == NULL)
    {
        *root = new_node;             // tree was empty — new node becomes the root
    }
	else if (value < parent->n)
    {
        parent->left = new_node;      // attach as left child
    }
	else
    {
        parent->right = new_node;     // attach as right child
    }
	return (new_node);
}

/* Search is simpler: just follow the BST rule until we find the value or fall off. */
binary_tree_t *bst_search(binary_tree_t *root, int value)
{
	while (root != NULL)
	{
		if (value == root->n)
			return (root);          // found it
		if (value < root->n)
			root = root->left;      // too big — go left
		else
			root = root->right;     // too small — go right
	}
	return (NULL); // fell off the tree: value not present
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
