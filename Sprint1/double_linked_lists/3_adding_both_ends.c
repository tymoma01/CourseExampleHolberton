#include <stdio.h>
#include <stdlib.h>

typedef struct dlist_s {
    char *tab;
    struct dlist_s *prev;
    struct dlist_s *next;
} dlist_t;

void push_front(dlist_t **head, char *name)
{
    dlist_t *new = malloc(sizeof(dlist_t));
    new->tab = name;
    new->prev = NULL;
    new->next = *head;

    if (*head)
        (*head)->prev = new;

    *head = new;
}

void push_back(dlist_t **head, char *name)
{
    dlist_t *new = malloc(sizeof(dlist_t));
    new->tab = name;
    new->next = NULL;

    if (*head == NULL)
    {
        new->prev = NULL;
        *head = new;
        return;
    }

    dlist_t *tmp = *head;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = new;
    new->prev = tmp;
}

int main(void)
{
    dlist_t *tabs = NULL;

    push_front(&tabs, "Home");
    push_back(&tabs, "GitHub");
    push_back(&tabs, "Holberton");

    printf("Front: %s\n", tabs->tab);
    printf("Back: %s\n", tabs->next->next->tab);

    return 0;
}
