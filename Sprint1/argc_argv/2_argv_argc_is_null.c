#include <stdio.h>

int main(int argc, char **argv)
{
    printf("argv[argc] = %p\n", (void *)argv[argc]);
    if (argv[argc] == NULL)
        printf("Yes: argv[argc] is NULL\n");
    return 0;
}

// ./a.out a b c