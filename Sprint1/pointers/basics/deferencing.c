#include <stdio.h>

int main(void)
{
    int n = 98;
    int *p = &n;

    // int *pointer;
    // *pointer = 10;
    
    printf("n   = %d\n", n);
    printf("*p  = %d\n", *p);

    *p = 402; /* writes into n */
    printf("n   = %d\n", n);

    return 0;
}
