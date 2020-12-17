/* Dev Patel */
/* Prototype to test the iterate function for the linked list */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "node.h"

/* Comparison function for inserting elements to list */
int numOrder(void *data1, void *data2) {
    return *(int *)data1 < *(int *)data2;
}

/* Criteria function to delete all elements */
int alwaysTrue(void *data){
    return 1;
}

/* Action function to test iterate */
void action(void *data) {

    printf("Data: %d\n", *(int *)data);
}

/* Iterates over the linked list, calling the given function on each node */
void iterate(void *head, ActionFunction doThis) {

    /* Iterate through all nodes, calling the function on each node's data */
    while (head != NULL){
        
        doThis(((Node *)head)->data);
        head = ((Node *)head)->next;
    }
}

int main() {

    void *head = NULL;
    int data[10] = {4, 7, 3, 8, 1, 6, 2, 5, 10, 9}, i;

    printf("Inserting elements into list:\n");
    for (i = 0; i < 10; i++) insert(&head, &data[i], &numOrder, 1);

    printf("\nIterating over elements:\n");
    iterate(head, &action);

    printf("\nDeleting all elements:\n");
    deleteSome(&head, &alwaysTrue, &action, 1);

    return 0;
}

