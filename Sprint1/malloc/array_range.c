#include "main.h"
#include <stdlib.h>

int *array_range(int min, int max)
{
	int *a, i, len;

	if (min > max){
        return (NULL);
    }

	len = max - min + 1;
	a = malloc((unsigned int)len * sizeof(int));

	if (!a){
		return (NULL);
    }

	for (i = 0; i < len; i++){
        a[i] = min + i;
    }
    free(a);
	return (a);
}
