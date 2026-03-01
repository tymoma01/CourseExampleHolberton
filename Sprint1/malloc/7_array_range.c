// a function allocates heap memory and returns the pointer to the caller.

// The caller now OWNS the memory and is responsible for calling free().
// This is a core concept in C memory management.

// !!! SPOT THE BUG !!!

// Other points:
//   - Input validation (min > max) before allocating anything.
//   - Returning NULL on both invalid input and failed malloc lets the
//     caller handle all error cases with a single NULL check.
//   - The cast (unsigned int) avoids a signed/unsigned comparison warning.


#include "main.h"
#include <stdlib.h>

int *array_range(int min, int max)
{
	int *a, i, len;

	if (min > max){         // validate input before allocating
        return (NULL);
    }

	len = max - min + 1;
	a = malloc((int)len * sizeof(int));

	if (!a){                // always check malloc's return value
		return (NULL);
    }

	for (i = 0; i < len; i++){
        a[i] = min + i;
    }

    // free(a);
	return (a); 
}


// free(a) is called BEFORE return(a).
// After free(), the memory is no longer valid. Returning and then
// using that pointer in main() is a USE-AFTER-FREE — undefined behavior.
// The fix: remove the free(a) here and let the caller free the memory.
// BUG: freeing before returning — caller receives a dangling pointer
// undefined behavior: this pointer points to freed memory