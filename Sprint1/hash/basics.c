#include <stdio.h>
#include "hash_tables.h"

/**
 * bad_hash - very bad hash function: uses only first character
 * @str: key
 *
 * Return: hash value (not reduced to table size)
 */
unsigned long int bad_hash(const unsigned char *str)
{
	if (str == NULL || str[0] == '\0')
		return (0);

	return ((unsigned long int)str[0]);
}

/**
 * hash_djb2 - good string hash function (classic djb2)
 * @str: key
 *
 * Return: hash value (not reduced to table size)
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c;
	}

	return (hash);
}

/**
 * key_index - gives the index of a key in an array of size @size
 * @key: key
 * @size: size of the array of the hash table
 *
 * Return: the index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

/**
 * print_hashes - prints bad and good hashes for a list of keys
 * @keys: NULL-terminated array of C strings
 * @size: size of the hash table
 */
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

/**
 * main - demo of hash functions and indices
 *
 * Return: Always 0.
 */
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
