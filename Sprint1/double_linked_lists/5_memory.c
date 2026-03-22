#include <stdio.h>
#include <stdlib.h>

typedef struct dlist_s {
    int n;
    struct dlist_s *prev;
    struct dlist_s *next;
} dlist_t;

void free_dlist(dlist_t *head)
{
    dlist_t *tmp;

    while (head)
    {
        tmp = head->next;
        free(head->n);
        free(head);
        head = tmp;
    }
}

int main(void)
{
    dlist_t *a = malloc(sizeof(dlist_t));
    dlist_t *b = malloc(sizeof(dlist_t));
    
    a->n = 10;
    a->prev = NULL;
    a->next = b;
    b->n = 20;
    b->prev = a;
    b->next = NULL;

    free_dlist(a);

    return 0;
}
