#include <stdio.h>

void print_matrix(int a[][3], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int m[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    print_matrix(m, 2);
    return 0;
}
