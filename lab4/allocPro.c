/* Dev Patel */
/* Prototype to test using the unreliable allocation library */

#include <stdio.h>
#include "altmem.h"


/* Attempts to allocate an int */
int *allocateInt(int num) {

    int *newNum;

    if (newNum = alternative_malloc(sizeof(int))) {

        *newNum = num;
        printf("DIAGNOSTIC: Successfully allocated space for %d.\n", num);

    }else{

        printf("ERROR: Failed to allocate space for %d.\n", num);
    }

    return newNum;
}

/* Frees the given variable */
void freeInt(void *num) {

    printf("Freeing %d.\n", *(int *)num);
    alternative_free(num);
    num = NULL;
}

int main() {

    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *ptrs[10], i;

    /* Attempts to allocate space for each int */
    for (i = 0; i < 10; i++) ptrs[i] = allocateInt(nums[i]);

    /* Frees each int that successfully allocated */
    for (i = 0; i < 10; i++) if (ptrs[i] != NULL) freeInt(ptrs[i]);

    return 0;
}

