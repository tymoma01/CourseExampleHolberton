#include <stdio.h>

int main(void)
{
    int a[5];

    *a = 98;
    *(a + 1) = 198;
    a[2] = 298;

    printf("a[0] = %d\n", a[0]);
    printf("a[1] = %d\n", *(a + 1));
    printf("a[2] = %d\n", a[2]);

    return 0;
}
