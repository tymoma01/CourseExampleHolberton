#include <stdio.h>
#include "hash_tables.h"

unsigned long int bad_hash(const unsigned char *str)
{
	if (str == NULL || str[0] == '\0')
		return (0);

	return ((unsigned long int)str[0]);
}

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381; // magic seed chosen by djb2's author for good distribution
	int c;

	while ((c = *str++)) // read one character at a time until '\0'
	{
		hash = ((hash << 5) + hash) + c; // hash * 33 + c  (fast multiply via bit-shift)
	}

	return (hash);
}

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size); // modulo reduces the hash to a valid array index
}


void print_hashes(const char **keys, unsigned long int size)
{
	int i;

	for (i = 0; keys[i] != NULL; i++)
	{
		unsigned long int bad = bad_hash(
				(const unsigned char *)keys[i]);
		unsigned long int good = hash_djb2(
				(const unsigned char *)keys[i]);
		unsigned long int idx = key_index(
				(const unsigned char *)keys[i], size);

		printf("Key: %-12s | bad_hash: %-4lu | djb2: %-12lu | index(size=%lu): %lu\n",
		       keys[i], bad, good, size, idx);
	}
}


int main(void)
{
	const char *keys[] = {
		"John Smith",
		"Jane Doe",
		"James Bond",
		"Sandra Dee",
		"Jack Black",
		NULL
	};
	unsigned long int size = 8;

	print_hashes(keys, size);

	return (0);
}
