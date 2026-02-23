// // Array decay means that, in most expressions, an array value is converted by the compiler into a pointer to the first element.

// #include <stdio.h>

// int main(void)
// {
//     char b[98];

//     printf("b         = %p\n", (void *)b);
//     printf("&b        = %p\n", (void *)&b);
//     printf("sizeof(b) = %lu\n", (unsigned long)sizeof(b));
//     printf("sizeof(&b)= %lu\n", (unsigned long)sizeof(&b));

//     return 0;
// }


#include <stdio.h>

int main(void)
{
    int a[5];

    printf("a       = %p\n", (void *)a);
    printf("a + 1   = %p\n", (void *)(a + 1));
    printf("a + 2   = %p\n", (void *)(a + 2));

    return 0;
}
