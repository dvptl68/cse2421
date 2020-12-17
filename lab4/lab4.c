/* Dev Patel */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "structs.h"
#include "lib8ball.h"
#include "lab4.h"
#include "movement.h"
#include "allocate.h"
#include "table.h"
#include "output.h"
#include "debug.h"

/* Criteria function to delete all balls after simulation is over */
int deleteAll(void *data) {
    return 1;
}

/* Criteria function to check if ball is moving */
int stillMoving(void *data) {
    return (*(struct Ball *)data).Vx > 0.0 || (*(struct Ball *)data).Vy > 0.0;
}

/* Handle all simulation ball movement */
void ballMovement(struct Sim *table) {

    /* Calculate next position for each ball */
    iterate(table->head, &moveBall);

    /* Delete balls that are in pockets */
    deleteSome(&table->head, &inPocket, &ballPocket, TEXT);

    /* Reflect balls that are on rails - no need to check for pockets at this point since they have been deleted */
    iterate(table->head, &reflectBall);

    /* Apply friction to remaining balls */
    iterate(table->head, &applyFriction);

    /* Increase elapsed time */
    table->elapsed += table->dT;
}

/* Run simulation */
void runSim(struct Sim *table) {

    /* Set lowest dT */
    table->dT = least(table->head, &ballDT);
    if (DEBUG) printf("runSim - dT: %lf\n", table->dT);

    /* Initial setup before simulation starts */
    updateOutput(table);

    /* Start simulation */
    while (table->head != NULL && some(table->head, &stillMoving)){

        /* Run one frame of simulation */
        ballMovement(table);

        /* Update simulation each frame */
        updateOutput(table);
    }

    /* Delay two seconds if necessary */
    if (GRAPHICS) millisleep((unsigned int) SLEEP_TIME);

    /* Output end of simulation */
    outputEnd(table->elapsed);

    /* Delete stopped balls */
    deleteSome(&table->head, &deleteAll, &deleteBall, TEXT);
}

/* Read balls while input keeps going */
int readBalls(struct Sim *table, char *fileName) {

    int scanVal;
    struct Ball bl = {0};

    /* Scan ball input and terminate with invalid input */
    while ((scanVal = fscanf(table->fp, "%d %lf %lf %lf %lf", &bl.ballNum, &bl.X, &bl.Y, &bl.Vx, &bl.Vy)) == INPUT_NUM){

        if (DEBUG) printf("readBalls - Read data: %d %lf %lf %lf %lf\n", bl.ballNum, bl.X, bl.Y, bl.Vx, bl.Vy);

        /* Add ball to linked list */
        bl.table = table;
        addBall(&bl);
    }

    if (TEXT) printf("fscanf returned %d\n", scanVal);

    /* Attempt to close input file */
    printf((fclose(table->fp)) ? "ERROR: Unable to close input file %s.\n" : "DIAGNOSTIC: Closed input file %s.\n", fileName);

    return scanVal;
}

/* Read balls and run simulation if necessary */
void attemptSim(struct Sim *table, char *fileName) {

    /* Read balls */
    int scanVal = readBalls(table, fileName);

    /* No need to run sim if no balls are read in */
    if (table->head == NULL) return;

    /* Initialize graphics if necessary, ending program if graphics fail */
    if (GRAPHICS && !eb_initialize(0)) return;

    /* Run simulation */
    runSim(table);

    /* Tear down graphics if necessary */
    if (GRAPHICS) eb_teardown();
}

/* Attempt to open input file */
int openFile(struct Sim *table, char *fileName) {

    if (table->fp = fopen(fileName, "r")) {

        printf("DIAGNOSTIC: Successfully opened %s for input.\n", fileName);
        return 1;

    }else{

        printf("ERROR: Unable to open %s for input.\n", fileName);
        return 0;
    }
}

/* Run sim and record total runtime */
int main(int argc, char **argv) {

    /* Create sim and start total runtime */
    double start = now();
    struct Sim table = {0.0, DEFAULT_DT, NULL, NULL};

    /* Check if there is a file input argument */
    if (argc > 1){

        /* Read balls and attempt to run simulation if file successfully opens */
        if (openFile(&table, argv[1])) attemptSim(&table, argv[1]); 

    }else{

        printf("ERROR: No input file given.\n");
    }

    /* Print final runtime */
    printf("Total run time is %11.9lf seconds.\n", (now() - start));

    return EXIT_SUCCESS;
}

