#include <stdio.h>

int main(void)
{
    int a[3][5] = {
        {1,  2,  3,  4,  5},
        {10, 20, 30, 40, 50},
        {5,  10, 15, 20, 25}
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
    }
    return 0;
}