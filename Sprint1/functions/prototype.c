#include <stdio.h>

// prototype (declaration)
int max(int, int);

int main(void)
{
    printf("max = %d\n", max(75, 57));
    return 0;
}

//definition
int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}
