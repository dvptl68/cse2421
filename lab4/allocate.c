/* Dev Patel */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "structs.h"
#include "allocate.h"
#include "debug.h"
#include "altmem.h"

/* Define ordering for balls to be added to list */
int ballOrder(void *data1, void *data2) {

    return (*(struct Ball *)data1).ballNum < (*(struct Ball *)data2).ballNum;
}

/* Counts number of ball allocations */
static void countAlloc() {

    static int allocated = 0;
    if (TEXT) printf("DIAGNOSTIC: %d balls allocated.\n", ++allocated);
}

/* Counts number of freed balls */
static void countFree() {

    static int freed = 0;
    if (TEXT) printf("DIAGNOSTIC: %d balls freed.\n", ++freed);
}

/* Disposal function for deleted balls */
void deleteBall(void *data) {

    alternative_free(data);
    data = NULL;
    countFree();
}

/* Inserts ball to list */
void insertToList(void *current, struct Ball *bl) {

    /* Attempt to add ball to list, free allocated space if insertion fails */
    if (!insert(&bl->table->head, current, &ballOrder, TEXT)){

        printf("ERROR: Failed to insert ball %d to list.\n", bl->ballNum);

        /* Free ball and count number of frees */
        deleteBall(current);
    }
}

/* Allocates space for a ball and adds to list */
void addBall(struct Ball *bl) {

    /* Allocate space and check for success */
    void *current = alternative_malloc(sizeof(struct Ball));

    if (current != NULL){

        /* Count number of allocations */
        countAlloc();

        /* Attemptt to add ball to list */
        *(struct Ball *)current = *bl;
        insertToList(current, bl);

    }else{

        printf("ERROR: Failed to allocate ball %d.\n", bl->ballNum);
    }
}

/* Disposal function for balls that drop into pockets */
void ballPocket(void *data) {

    if (TEXT) printf("\nBall %d dropped into a pocket.\n", (*(struct Ball *)data).ballNum);
    deleteBall(data);
}

