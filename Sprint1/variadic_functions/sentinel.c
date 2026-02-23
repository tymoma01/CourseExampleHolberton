#include <stdarg.h>
#include <stdio.h>

// enum Opt {  
//     OPT_RED = 1, 
//     OPT_BOLD = 2, 
//     OPT_BLINK = 4, 
//     OPT_END = 0 
// };

// Use of va_start, va_arg and va_end because we don't know how many arguments we are going to have.

int make_style(int first, ...) // One or more arguments accepted with this notation
{
    va_list ap; // Cursor that will go through each unnamed arguments
    int mask = 0;
    int opt = first;

    va_start(ap, first); // Tells the cursor where to start

    while (opt != 0)
    {
        mask = mask | opt;
        opt = va_arg(ap, int); // Tells the cursor to go to the next argument
    }

    va_end(ap); // Tells the cursor where to stop
    return mask;
}

int main(void)
{
    int style = make_style(1, 2, 3);
    printf("style mask = %d\n", style);
    return 0;
}
