#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len2 = _printf("%");
    len = printf("%");
    if (len != len2){
        printf("lengths differ")
    }
	fflush(stdout);
	printf("\nlen2 = %d\n", len2);

	return (0);
}