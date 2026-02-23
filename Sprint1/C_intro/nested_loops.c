#include <stdio.h>

int main(void)
{
    int i, j;

    // // Outer loop controls the rows
    // for (i = 1; i <= 5; i++)
    // {
    //     // Inner loop controls the columns
    //     for (j = 1; j <= 5; j++)
    //     {
    //         printf("%d\t", i * j);  // Print the product
    //     }
    //     printf("\n");  // Move to the next line after each row
    // }

    i = 0;

    while (i < 10){
        i++;
        printf("%d\n", i);
    }


    return 0;
}
