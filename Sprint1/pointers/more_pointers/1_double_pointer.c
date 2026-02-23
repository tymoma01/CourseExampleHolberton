#include <stdio.h>

int main(void)
{
    int a = 100;
    int *ptr = &a; // ptr stores the address of a
    int **dptr = &ptr; // dptr stores the address of ptr

    // tptr -> dptr -> ptr -> a -> 100

    printf("a      = %d\n", a);
    printf("*ptr   = %d\n", *ptr);
    printf("**dptr = %d\n", **dptr);

    printf("&a    = %p\n", (void *)&a);
    printf("ptr   = %p\n", (void *)ptr);
    printf("&ptr  = %p\n", (void *)&ptr);
    printf("dptr  = %p\n", (void *)dptr);

    return 0;
}