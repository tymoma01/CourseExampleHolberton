#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct query_s {
    char *q;
    struct query_s *next;
} query_t;

void add_recent(query_t **head, const char *text)
{
    query_t *new_node = malloc(sizeof(query_t));
    new_node->q = strdup(text);
    new_node->next = *head;
    *head = new_node;
}

void print_queries(query_t *head)
{
    while (head)
    {
        printf("%s\n", head->q);
        head = head->next;
    }
}

int main(void)
{
    query_t *history = NULL;

    add_recent(&history, "weather today");
    add_recent(&history, "nearest cafe");
    add_recent(&history, "C linked list tutorial");

    print_queries(history);

    return 0;
}
