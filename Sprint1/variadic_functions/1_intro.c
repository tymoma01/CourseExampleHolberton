#include <stdarg.h>
#include <stdio.h>

// A variadic function accepts a variable number of arguments.
// The signature uses "..." (ellipsis) after at least one named parameter.

// Four macros from <stdarg.h> are required to access the extra arguments:
//   va_list  ap;            — declares a cursor that walks through arguments
//   va_start(ap, last);     — initializes the cursor; `last` is the last named param
//   va_arg(ap, type);       — fetches the next argument as `type` and advances the cursor
//   va_end(ap);             — cleans up (always call this before returning)

// The function itself must know how many extra arguments were passed.
// The simplest way: pass the count explicitly (shown here).


int sum(int count, ...)
{
    va_list ap;
    int total = 0;

    va_start(ap, count); // start right after 'count'

    for (int i = 0; i < count; i++)
    {
        total += va_arg(ap, int); // fetch next int and advance cursor
    }

    va_end(ap); // always clean up
    return total;
}

int main(void)
{
    printf("sum(3,  1+2+3)          = %d\n", sum(3, 1, 2, 3));
    printf("sum(5,  10+20+30+40+50) = %d\n", sum(5, 10, 20, 30, 40, 50));
    printf("sum(0)                  = %d\n", sum(0));
    return 0;
}
