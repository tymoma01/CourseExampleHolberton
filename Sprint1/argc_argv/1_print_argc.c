#include <stdio.h>

int main(int argc, char **argv)
{
    // argc = number of arguments given (int)
    // argv = array of strings that the arguments given
    
    int i;

    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++)
        printf("argv[%d] = \"%s\"\n", i, argv[i]);

    return 0;
}

// ./a.out hello world