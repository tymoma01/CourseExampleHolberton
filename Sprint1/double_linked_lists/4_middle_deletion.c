#include <stdio.h>
#include <stdlib.h>

typedef struct dlist_s {
    int val;
    struct dlist_s *prev;
    struct dlist_s *next;
} dlist_t;

void delete_node(dlist_t **head, dlist_t *node)
{
    if (node->prev)
        node->prev->next = node->next;
    else
        // deleting the head
        *head = node->next;

    if (node->next)
        node->next->prev = node->prev;

    free(node);
}

int main(void)
{
    dlist_t *a = malloc(sizeof(dlist_t));
    dlist_t *b = malloc(sizeof(dlist_t));
    dlist_t *c = malloc(sizeof(dlist_t));

    a->val = 1; 
    a->prev = NULL; 
    a->next = b;

    b->val = 2; 
    b->prev = a;
    b->next = c;

    c->val = 3; 
    c->prev = b;
    c->next = NULL;

    dlist_t *head = a;

    delete_node(&head, b);

    printf("List after deletion: %d <-> %d\n", head->val, head->next->val);

    free(a);
    free(c);

    return 0;
}
