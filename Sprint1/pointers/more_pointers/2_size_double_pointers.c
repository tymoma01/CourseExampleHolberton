#include <stdio.h>

int main(void)
{
    int *p = NULL;
    int **pp = NULL;

    printf("sizeof(p)  = %lu\n", (unsigned long)sizeof(p));
    printf("sizeof(pp) = %lu\n", (unsigned long)sizeof(pp));
    return 0;
}