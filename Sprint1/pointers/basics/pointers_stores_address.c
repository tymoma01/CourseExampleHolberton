#include <stdio.h>

int main(void)
{
    int n = 98;
    int *p = &n;

    printf("&n  = %p\n", (void *)&n);
    printf("p   = %p\n", (void *)p);

    return 0;
}
