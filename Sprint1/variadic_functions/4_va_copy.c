
#include <stdarg.h>
#include <stdio.h>

void vlog_to(FILE *out, const char *fmt, va_list ap){
    vfprintf(out, fmt, ap);
}

void log_to_two(FILE *a, FILE *b, const char *fmt, ...){
    va_list ap1, ap2;
    va_start(ap1, fmt);
    va_copy(ap2, ap1);

    vlog_to(a, fmt, ap1);
    vlog_to(b, fmt, ap2);

    va_end(ap2);
    va_end(ap1);
}

int main(void){
    log_to_two(stdout, stderr, "user=%s id=%d\n", "thomas", 42);
    return 0;
}
