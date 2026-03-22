#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char *word;
    struct node_s *next;
} node_t;

/* Append a new node at the END of the list */
void add_tail(node_t **head, const char *text)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(text);
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    /* Walk to the last node */
    node_t *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}

void print_list(node_t *head)
{
    while (head)
    {
        printf("%s\n", head->word);
        head = head->next;
    }
}

int main(void)
{
    node_t *head = NULL;

    /* Nodes are stored in insertion order (unlike head insertion) */
    add_tail(&head, "first");
    add_tail(&head, "second");
    add_tail(&head, "third");

    print_list(head);

    return 0;
}
