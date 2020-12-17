/* Dev Patel */
/* Prototype to test using function pointers for the linked list */

#include <stdio.h>
#include "linkedlist.h"

/* Prints an integer (action)*/
void printNum(void *data) {
    printf("Num: %d\n", *(int *)data);
}

/* Compares two integers to see which is smaller (comparison) */
int compareInt(void *data1, void *data2) {
    return *(int *)data1 < *(int *)data2;
}

/* Checks that the integer is positive (criteria) */
int isPositive(void *data) {
    return *(int *)data > 0;
}

/* Returns data divided by 17 (numeric) */
double divideBy17(void *data) {
    return *(int *)data / 17.0;
}

int main() {

    /* Declare all pointers needed */
    void *data, *data2;
    void (*action)(void *data) = &printNum;
    int (*compare)(void *data, void *data2) = &compareInt;
    int (*criteria)(void *data) = &isPositive;
    double (*numeric)(void *data) = &divideBy17;

    int i = 10, j = -20;
    data = &i, data2 = &j;

    /* Test each function pointer twice */
    action(data);
    action(data2);
    printf("Is %d less than %d? %d\n", i, j, compare(data, data2));
    printf("Is %d less than %d? %d\n", j, i, compare(data2, data));
    printf("Is %d positive? %d\n", i, criteria(data));
    printf("Is %d positive? %d\n", j, criteria(data2));
    printf("%d/17: %lf\n", i, numeric(data));
    printf("%d/17: %lf\n", j, numeric(data2));

    return 0;
}

