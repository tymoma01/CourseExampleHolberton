#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        argv[1][0] = 'X'; // may crash on some systems
        printf("%s\n", argv[1]);
    }
    return 0;
}