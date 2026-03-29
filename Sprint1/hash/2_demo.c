#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381; // magic seed chosen by djb2's author for good distribution
	int c;

	while ((c = *str++)) // read one character at a time until '\0'
		hash = ((hash << 5) + hash) + c; // hash * 33 + c  (fast multiply via bit-shift)

	return (hash);
}

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size); // modulo reduces the hash to a valid array index
}


hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL) 
    {
		return (NULL);
    }

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++) 
    {
		ht->array[i] = NULL;
    }

	return (ht);
}

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
    {
		return (NULL);
    }

	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}


int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *tmp;

	if (ht == NULL || key == NULL || *key == '\0')
    {
		return (0);
    }

	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];

	// Update value if key already exists in the chain
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			char *new_val = strdup(value);

			if (new_val == NULL)
            {
				return (0);
            }
			free(tmp->value);
			tmp->value = new_val;
			return (1);
		}
		tmp = tmp->next;
	}

	// Key not found: add a new node at the beginning (chaining)
	node = create_node(key, value);
	if (node == NULL)
    {
		return (0);
    }

	node->next = ht->array[idx]; // new node points to the current head of the chain
	ht->array[idx] = node;       // new node becomes the new head (prepend = O(1))

	return (1);
}


void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		printf("[%lu]", i);
		node = ht->array[i];
		while (node != NULL)
		{
			printf(" -> (%s : %s)", node->key, node->value);
			node = node->next;
		}
		printf("\n");
	}
}

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			tmp = node->next; /* save next before freeing current node */
			free(node->key);
			free(node->value);
			free(node);
			node = tmp; /* advance to the saved next node */
		}
	}

	free(ht->array);
	free(ht);
}


int main(void)
{
	hash_table_t *ht;
	unsigned long int size = 4;

	ht = hash_table_create(size);
	if (ht == NULL)
	{
		printf("Failed to create hash table\n");
		return (1);
	}

	hash_table_set(ht, "venghour", "0494110150");
	hash_table_set(ht, "lachie", "0494118247");
	hash_table_set(ht, "sam", "0494136452");
	hash_table_set(ht, "sebastion", "0494235151");
	hash_table_set(ht, "shams", "0494135784");
    hash_table_set(ht, "joshua", "0494112756");
    hash_table_set(ht, "Joe", "0494135784");
    hash_table_set(ht, "Heidi", "0494135781");
    hash_table_set(ht, "John Smith", "0494135712");

	printf("Hash table with size = %lu (expect collisions):\n", size);
	hash_table_print(ht);

	hash_table_delete(ht);
	return (0);
}
