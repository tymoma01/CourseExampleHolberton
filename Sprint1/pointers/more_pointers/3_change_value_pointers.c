#include <stdio.h>

// void set_ptr(int *p)
// {
//     int x = 42;
//     p = &x; 
// }


// changes are only locally
// main:
// p  --->  &a

// function:
// p_copy ---> 42

// I only changed p_copy



void set_ptr(int **pp)
{
    static int x = 42; // static means it still exists after the function returns
    *pp = &x;
}

// **pp -> *pp -> variable -> ?

// *pp means:
// Go to the address stored in pp (which is &p)
// That location is p
// Modify that

int main(void)
{
    int a = 10;
    int *p = &a;

    printf("Before: *p = %d\n", *p);
    set_ptr(&p);
    printf("After : *p = %d\n", *p);
    return 0;
}



