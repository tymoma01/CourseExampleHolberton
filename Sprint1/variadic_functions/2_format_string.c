#include <stdarg.h>
#include <stdio.h>

// How to handle MIXED TYPES?
// The most common solution: a format string whose characters encode
// the type of each following argument (exactly like printf).

// The function walks the format string character by character and
// calls va_arg with the matching type for each specifier.

// IMPORTANT — float promotion rule:
//   When a float is passed to a variadic function it is automatically
//   promoted to double.  Always use va_arg(ap, double), never float.


void print_args(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            if (*fmt == 'd')
            {
                printf("int    : %d\n", va_arg(ap, int));
            }
            else if (*fmt == 'f')
            {
                printf("double : %f\n", va_arg(ap, double)); // float → double
            }
            else if (*fmt == 's')
            {
                printf("string : %s\n", va_arg(ap, char *));
            }
            else if (*fmt == 'c')
            {
                printf("char   : %c\n", va_arg(ap, int)); // char → int
            }
        }
        fmt++;
    }

    va_end(ap);
}

int main(void)
{
    print_args("%s%d%f%c", "Thomas", 25, 3.14, 'Y');
    return 0;
}
