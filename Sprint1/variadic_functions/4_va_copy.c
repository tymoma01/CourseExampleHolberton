#include <stdarg.h>
#include <stdio.h>

/*
 * VARIADIC FUNCTIONS — va_copy
 * =============================
 * Once va_start has been called, the va_list cursor can only be walked
 * forward — there is no rewind.  If you need to pass the same argument
 * list to two different functions (or traverse it twice), you must
 * duplicate it with va_copy BEFORE the first traversal consumes it.
 *
 *   va_copy(dst, src);   — creates an independent copy of src into dst
 *
 * Each copy must be cleaned up with its own va_end call.
 *
 * Practical use case: write the same log line to stdout AND to a log file.
 */

/* Helper: forwards a va_list to vfprintf — does NOT call va_end */
void vlog_to(FILE *out, const char *fmt, va_list ap)
{
    vfprintf(out, fmt, ap);
}

/* Writes the formatted message to two different FILE streams */
void log_to_two(FILE *a, FILE *b, const char *fmt, ...)
{
    va_list ap1, ap2;

    va_start(ap1, fmt);
    va_copy(ap2, ap1);      /* duplicate before ap1 is consumed by vlog_to */

    vlog_to(a, fmt, ap1);   /* ap1 is consumed here */
    vlog_to(b, fmt, ap2);   /* ap2 is consumed here — still has the original args */

    va_end(ap1);            /* clean up both copies */
    va_end(ap2);
}

int main(void)
{
    /* This prints to stdout AND stderr with a single call */
    log_to_two(stdout, stderr, "user=%s id=%d\n", "alice", 42);
    return 0;
}
