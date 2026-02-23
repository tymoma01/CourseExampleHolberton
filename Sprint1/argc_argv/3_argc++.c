#include <stdio.h>

int main(int argc, char **argv)
{
    while (argc--) // while argc is not 0, gets decreased everytime 
    {
        printf("%s\n", *argv);
        argv++; // move to next pointer (element) in the array
    }
    return 0;
}

// ./a.out abcde text hello