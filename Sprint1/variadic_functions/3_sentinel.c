#include <stdarg.h>
#include <stdio.h>

/*
 * VARIADIC FUNCTIONS — Sentinel pattern
 * =======================================
 * Another way to signal "no more arguments" is a sentinel value:
 * a special argument the caller always passes last to mean "stop here".
 *
 * Here the sentinel is 0.  Each non-zero argument is a flag bit that
 * gets OR-ed into a bitmask.  Passing 0 last tells the function to stop.
 *
 * Common real-world sentinels:
 *   - NULL  for pointer/string lists  (e.g. execl)
 *   - -1    for int lists
 *   - 0     for flag/enum lists (as shown here)
 *
 * The caller MUST always pass the sentinel — forgetting it is undefined behaviour.
 */

enum Style {
    OPT_RED   = 1,  /* bit 0 */
    OPT_BOLD  = 2,  /* bit 1 */
    OPT_BLINK = 4,  /* bit 2 */
    OPT_END   = 0   /* sentinel — signals end of argument list */
};

int make_style(int first, ...)  /* accepts one or more flag arguments */
{
    va_list ap;
    int     mask = 0;
    int     opt  = first;

    va_start(ap, first);

    while (opt != OPT_END)      /* keep going until the sentinel is reached */
    {
        mask |= opt;
        opt = va_arg(ap, int);  /* fetch next flag and advance cursor */
    }

    va_end(ap);
    return mask;
}

int main(void)
{
    /* Always terminate the argument list with the sentinel OPT_END (0) */
    int style = make_style(OPT_RED, OPT_BOLD, OPT_END);
    printf("RED | BOLD       mask = %d\n", style);        /* 3  (1|2)   */

    style = make_style(OPT_RED, OPT_BOLD, OPT_BLINK, OPT_END);
    printf("RED | BOLD | BLINK mask = %d\n", style);      /* 7  (1|2|4) */

    return 0;
}
