/* Dev Patel */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "allocate.h"
#include "structs.h"
#include "debug.h"

/* Define ordering for balls to be added to list */
int ballOrder(void *data1, void *data2) {

    return (*(struct Ball *)data1).ballNum < (*(struct Ball *)data2).ballNum;
}

/* Counts number of ball allocations */
void countAlloc() {

    static int allocated = 0;
    if (TEXT) printf("DIAGNOSTIC: %d balls allocated.\n", ++allocated);
}

/* Counts number of freed balls */
void countFree() {

    static int freed = 0;
    if (TEXT) printf("DIAGNOSTIC: %d balls freed.\n", ++freed);
}

/* Disposal function for deleted balls */
void deleteBall(void *data) {

    free(data);
    data = NULL;
    countFree();
}

/* Inserts ball to list */
void insertToList(void *current, struct Ball *bl) {

    /* Attempt to add ball to list, free allocated space if insertion fails */
    if (!insert(&bl->table->head, current, &ballOrder, TEXT)){

        printf("ERROR - failed to insert ball to list\n");

        /* Free ball and count number of frees */
        deleteBall(current);
    }
}

/* Allocates space for a ball and adds to list */
void addBall(struct Ball *bl) {

    /* Allocate space and check for success */
    void *current = malloc(sizeof(struct Ball));

    if (current != NULL){

        /* Count number of allocations */
        countAlloc();

        /* Attemptt to add ball to list */
        *(struct Ball *)current = *bl;
        insertToList(current, bl);

    }else{

        printf("ERROR - failed to allocate ball %d\n", bl->ballNum);
    }
}

/* Disposal function for balls that drop into pockets */
void ballPocket(void *data) {

    if (TEXT) printf("\nBall %d dropped into a pocket.\n", (*(struct Ball *)data).ballNum);
    deleteBall(data);
}

