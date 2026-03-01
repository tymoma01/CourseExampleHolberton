#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    char *arr;

    n = 5;

    arr = malloc(n * sizeof(char));

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'd';
    arr[4] = 'e';

    printf("%s\n", arr);

    free(arr);
    return(0);
}

