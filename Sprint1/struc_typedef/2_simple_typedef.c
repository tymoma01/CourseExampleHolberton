#include <stdio.h>

// Give a shorter name to an existing type
typedef unsigned char uchar;

int main(void)
{
    // same as: unsigned char r = 255
    uchar r = 255; 

    printf("byte r = %u\n", (unsigned int)r);
    return (0);
}

