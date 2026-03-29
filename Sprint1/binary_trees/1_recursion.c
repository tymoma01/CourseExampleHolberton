#include <stdio.h>

/*
 * Every recursive function needs two things:
 *   1. A BASE CASE  — the condition that stops the recursion
 *   2. A RECURSIVE CALL — calling itself with a "smaller" problem
 *
 * Call stack for countdown(3):
 *
 *   countdown(3)  → prints 3, then calls countdown(2)
 *     countdown(2)  → prints 2, then calls countdown(1)
 *       countdown(1)  → prints 1, then calls countdown(0)
 *         countdown(0)  → prints "Ready to go!", returns   ← base case
 *       countdown(1) resumes and returns
 *     countdown(2) resumes and returns
 *   countdown(3) resumes and returns
 *
 * Each call is paused and saved on the stack until its inner call returns.
 */

void countdown(int n)
{
    if (n == 0)                     // BASE CASE: nothing left to count down
    {
        printf("Ready to go!\n");
        return; // STOP the recursion
    }

    printf("%d\n", n);              // do some work BEFORE the recursive call

    countdown(n - 1); // RECURSIVE CALL — same function, smaller problem
}

int main(void)
{
    countdown(5);
    return 0;
}
