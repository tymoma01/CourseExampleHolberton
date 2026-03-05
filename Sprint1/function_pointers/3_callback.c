#include <stdio.h>

void print_square(int x)
{
    printf("%d\n", x * x);
}
void print_double(int x)
{
    printf("%d\n", x * 2);
}

void apply(int *arr, int n, void (*fn)(int)) 
// fn is a function pointer — it will be called for each element
{
    for (int i = 0; i < n; i++)
    {
        fn(arr[i]); // call whichever function was passed in
    }
}

int main(void)
{
    int arr[] = {1, 2, 3, 4};

    puts("squares:");
    apply(arr, 4, print_square); // pass print_square as the callback

    puts("doubles:");
    apply(arr, 4, print_double); // swap the behavior by passing a different function

    return 0;
}

// A function can receive another function as a parameter — this is called a callback.
// apply() doesn't know what fn does, it just calls it.
// The caller decides the behavior — apply() only handles the iteration.
