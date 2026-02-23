#include <stdio.h>

int main(void)
{
    int numbers[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Memory is freed automatically
    return (0);
}
