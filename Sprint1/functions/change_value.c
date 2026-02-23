// #include <stdio.h>

// void try_to_change(int x)
// {
//     x = 999;
// }

// int main(void)
// {
//     int n = 42;
//     try_to_change(n);
//     printf("n = %d\n", n);
//     return 0;
// }



// #include <stdio.h>

// void change(int *x)
// {
//     *x = 999; /* write into the caller's variable */
// }

// int main(void)
// {
//     int n = 42;
//     change(&n);
//     printf("n = %d\n", n); /* now 999 */
//     return 0;
// }




#include <stdio.h>

void set_first_to_0(int a[])
{
    a[0] = 0;
}

int main(void)
{
    int t[3] = {10, 20, 30};
    set_first_to_0(t);
    printf("%d %d %d\n", t[0], t[1], t[2]);
    return 0;
}
