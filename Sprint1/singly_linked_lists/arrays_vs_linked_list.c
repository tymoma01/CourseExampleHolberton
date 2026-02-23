#include <stdio.h>
#include <stdlib.h>

// define the linked list structure
typedef struct contact_s {
    char *name;
    struct contact_s *next;
} contact_t;


int main(void)
{
    // ARRAYS -> contiguous memory
    char *contacts[3] = {"Alice", "Bob", "Charlie"};  

    // constant-time access
    printf("Second contact: %s\n", contacts[1]);


    // LINKED LIST
    contact_t *head = NULL;                                
    contact_t *new = malloc(sizeof(contact_t));  

    new->name = "Alice";
    new->next = head; 
    head = new;   
    // -> fast insertion at the front

    /* Sequential access */
    printf("First contact: %s\n", head->name);

    return 0;
}
