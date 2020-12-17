/* Dev Patel */
/* Prototype to test the deleteSome function for the linked list */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "node.h"

/* Comparison function for inserting elements to list */
int numOrder(void *data1, void *data2) {
    return *(int *)data1 < *(int *)data2;
}

/* Criteria function to delete even numbers */
int even(void *data) {
    return *(int *)data % 2 == 0;
}

/* Criteria function to delete all elements */
int alwaysTrue(void *data){
    return 1;
}

/* Action function to test deleteSome */
void dispose(void *data) {

    printf("Deleted data: %d\n", *(int *)data);
}

/* Deletes elements from the linked list given a criteria function */
void deleteSome(void *p2head, CriteriaFunction mustGo, ActionFunction disposal, int verbose) {

    /* List iterator */
    Node **iter = p2head, *holder;
    static int freed;

    /* Iterate through list */
    while (*iter != NULL){

        if (mustGo((*iter)->data)){

            /* Change iterator value, dispose data */
            holder = *iter;
            *iter = (*iter)->next;
            disposal(holder->data);

            /* Free node - this will be a separate fuction in my actual lab */
            free(holder);
            holder = NULL;
            if (verbose) printf("DIAGNOSTIC: %d nodes freed.\n", ++freed);

        }else{

            /* Change iterator pointer */
            iter = &((*iter)->next);
        }
    }
}

int main() {

    void *head = NULL;
    int data[10] = {4, 7, 3, 8, 1, 6, 2, 5, 10, 9}, i;

    printf("Inserting elements into list:\n");
    for (i = 0; i < 10; i++) insert(&head, &data[i], &numOrder, 1);

    printf("\nDeleting even numbers:\n");
    deleteSome(&head, &even, &dispose, 1);

    printf("\nDeleting remaining elements:\n");
    deleteSome(&head, &alwaysTrue, &dispose, 1);

    return 0;
}

