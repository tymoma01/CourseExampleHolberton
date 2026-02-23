#include <stdio.h>

int main(void)
{
    char c = 'H';
    int n = 98;

    printf("Address of c: %p\n", (void *)&c);
    printf("Address of n: %p\n", (void *)&n);

    return 0;
}
