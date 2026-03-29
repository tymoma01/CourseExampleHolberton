#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    if (node == NULL)
        return (NULL);
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int max(int a, int b) { return (a > b ? a : b); }

int tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    return 1 + max(tree_height(tree->left), tree_height(tree->right));
}

// Print spaces
void print_spaces(int count)
{
    int i;
    for (i = 0; i < count; i++)
        printf(" ");
}

// Calculate power of 2
int power_of_2(int exp)
{
    int result = 1;
    int i;
    
    for (i = 0; i < exp; i++)
        result *= 2;
    return result;
}

// Print a level of the tree
void print_level_helper(const binary_tree_t *tree, int level, int offset, int width)
{
    int half;
    
    if (tree == NULL)
    {
        if (level == 0)
            print_spaces(width);
        else
        {
            half = width / 2;
            print_level_helper(NULL, level - 1, offset, half);
            print_level_helper(NULL, level - 1, offset + half, half);
        }
        return;
    }
    
    if (level == 0)
    {
        int padding = (width - 4) / 2;
        print_spaces(padding);
        printf("(%d)", tree->n);
        print_spaces(width - 4 - padding);
    }
    else
    {
        half = width / 2;
        print_level_helper(tree->left, level - 1, offset, half);
        print_level_helper(tree->right, level - 1, offset + half, half);
    }
}

// Print branches for a level
void print_branches_helper(const binary_tree_t *tree, int level, int offset, int width)
{
    int half, quarter;
    
    if (tree == NULL)
    {
        if (level == 0)
            print_spaces(width);
        else
        {
            half = width / 2;
            print_branches_helper(NULL, level - 1, offset, half);
            print_branches_helper(NULL, level - 1, offset + half, half);
        }
        return;
    }
    
    if (level == 0)
    {
        quarter = width / 4;
        print_spaces(quarter);
        
        if (tree->left)
            printf("/");
        else
            printf(" ");
        
        print_spaces(width / 2 - 2);
        
        if (tree->right)
            printf("\\");
        else
            printf(" ");
        
        print_spaces(quarter);
    }
    else
    {
        half = width / 2;
        print_branches_helper(tree->left, level - 1, offset, half);
        print_branches_helper(tree->right, level - 1, offset + half, half);
    }
}

// Main pretty-printer
void binary_tree_print_pretty(const binary_tree_t *tree)
{
    int h, level, width, offset;

    if (tree == NULL)
    {
        printf("(empty)\n");
        return;
    }

    h = tree_height(tree);
    width = 8 * power_of_2(h - 1);
    offset = 0;

    for (level = 0; level < h; level++)
    {
        print_level_helper(tree, level, offset, width);
        printf("\n");

        if (level < h - 1)
        {
            print_branches_helper(tree, level, offset, width);
            printf("\n");
        }
    }
}

#ifndef NO_MAIN
int main(void)
{
    binary_tree_t *root;

    /*
     *         (10)
     *        /    \
     *      (5)   (20)
     *      / \     \
     *    (2) (7)  (30)
     */
    root = binary_tree_node(NULL, 10);
    root->left = binary_tree_node(root, 5);
    root->right = binary_tree_node(root, 20);
    root->left->left = binary_tree_node(root->left, 2);
    root->left->right = binary_tree_node(root->left, 7);
    root->right->right = binary_tree_node(root->right, 30);

    binary_tree_print_pretty(root);

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return (0);
}
#endif /* NO_MAIN */
