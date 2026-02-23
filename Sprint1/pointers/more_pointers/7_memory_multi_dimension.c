#include <stdio.h>

int main(void)
{
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // char a[2][3] = {
    //     {'a', 'b', 'c'},
    //     {'d', 'e', 'f'} // + '\0'
    // };

    // &a[0][0] -> &a[0][1] -> &a[0][2] -> &a[1][0] -> &a[1][1] -> &a[1][2]

    printf("&a[0][0] = %p\n", (void *)&a[0][0]);
    printf("&a[0][1] = %p\n", (void *)&a[0][1]);
    printf("&a[0][2] = %p\n", (void *)&a[0][2]);
    printf("&a[1][0] = %p\n", (void *)&a[1][0]);
    printf("&a[1][1] = %p\n", (void *)&a[1][1]);
    printf("&a[1][2] = %p\n", (void *)&a[1][2]);

    // printf("a[5][0] = %d\n", a[5][0]);
    printf("&a[5][0] = %p\n", (void *)&a[5][0]);

// &a[0][0] = 0x16bbee890
// &a[0][1] = 0x16bbee894 -> computed by &a[0][0] + sizeof(int) = 4

// &a[2][0] = &a[1][2] + sizeof(int) = 4
// &a[5][0] = 0x16bbee890 + 3 x 4 x 4
    
    return 0;
}
