#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argv (as pointer) = %p\n", (void *)argv);
    printf("&argv[0]          = %p\n", (void *)&argv[0]);
    printf("argv[0] (string)  = %s\n", argv[0]);
    return 0;
}

// char *argv[] and char **argv are the same here
// In function parameters, char *argv[] decays to char **argv