#include <stdio.h>

int sum_array(int *p, int len)
{
    if (len == 0) // stop condition
        return 0;

    return *p + sum_array(p + 1, len - 1); // recursion: advance pointer
}

int main(void)
{
    int a[] = {10, 20, 30, 40};
    int n = (int)(sizeof(a) / sizeof(a[0]));

    printf("sum = %d\n", sum_array(a, n));
    return 0;
}