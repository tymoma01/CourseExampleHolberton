#include <stdio.h>
#include <stdlib.h>

typedef struct dlist_s {
    int n;
    struct dlist_s *prev;
    struct dlist_s *next;
} dlist_t;

void print_forward(dlist_t *head)
{
    while (head)
    {
        printf("%d", head->n);
        if (head->next)
            printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

void print_backward(dlist_t *head)
{
    // Walk to the tail first
    while (head->next)
        head = head->next;

    // Then walk back using prev
    while (head)
    {
        printf("%d", head->n);
        if (head->prev)
            printf(" <-> ");
        head = head->prev;
    }
    printf("\n");
}

int main(void)
{
    dlist_t *a = malloc(sizeof(dlist_t));
    dlist_t *b = malloc(sizeof(dlist_t));
    dlist_t *c = malloc(sizeof(dlist_t));

    a->n = 1; a->prev = NULL; a->next = b;
    b->n = 2; b->prev = a;   b->next = c;
    c->n = 3; c->prev = b;   c->next = NULL;

    printf("Forward:  ");
    print_forward(a);

    printf("Backward: ");
    print_backward(a);

    free(a);
    free(b);
    free(c);

    return 0;
}
