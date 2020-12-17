/* Dev Patel */
/* Prototype to test using linked list functions using function pointers from last prototype */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define TEXT 1

/* Prints an integer (action)*/
void printNum(void *data) {
    printf("Data: %d\n", *(int *)data);
}

/* Prints an integer and frees allocated memory */
void printFree(void *data) {
    printf("Freeing: %d\n", *(int *)data);
    free(data);
    data = NULL;
}

/* Compares two integers to see which is smaller (comparison) */
int compareInt(void *data1, void *data2) {
    return *(int *)data1 < *(int *)data2;
}

/* Checks that the integer above 9 (criteria) */
int isGreaterThan9(void *data) {
    return *(int *)data > 9;
}

/* Returns data divided by 17 (numeric) */
double divideBy17(void *data) {
    return *(int *)data / 17.0;
}

/* Insert 10 random elements to list */
void insert10(void **head) {

    int i;
    for (i = 0; i < 10; i++){
        void *data = malloc(sizeof(int));
	    *(int *)data = rand() % 20;
        if (insert(head, data, &compareInt, TEXT)){
            printf("Add successfull\n");
        }else{
            printf("Add failure\n");
        }
    }
}

/* Print all list elements */
void printAll(void *head) {

    iterate(head, &printNum);
}

/* Delete all elements greater than 9 */
void deleteGreater(void **head) {

    deleteSome(head, &isGreaterThan9, &printFree, TEXT);
}

int main() {

    /* Insert 10 elements between 0 and 20 to list, print, delete elements greater than 9, and print again */

    void *head = NULL;

    printf("Adding elements to list...\n");
    insert10(&head);

    printf("Current elements:\n");
    printAll(head);

    printf("Deleting elements greater than 9...\n");
    deleteGreater(&head);

    printf("Remaining elements:\n");
    printAll(head);

    return 0;
}

