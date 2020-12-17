/* Dev Patel */

#include <stdio.h>
#include <stdlib.h>
#include "lib8ball.h"
#include "linkedlist.h"
#include "lab3.h"
#include "movement.h"
#include "allocate.h"
#include "table.h"
#include "output.h"
#include "structs.h"
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

    /* Output end of simulation */
    outputEnd(table->elapsed);

    /* Delete stopped balls */
    deleteSome(&table->head, &deleteAll, &deleteBall, TEXT);
}

/* Read balls while input keeps going */
int readBalls(struct Sim *table) {

    int scanVal;
    struct Ball bl = {0};

    /* Scan ball input and terminate with invalid input */
    while ((scanVal = scanf("%d %lf %lf %lf %lf", &bl.ballNum, &bl.X, &bl.Y, &bl.Vx, &bl.Vy)) == INPUT_NUM){

        if (DEBUG) printf("readBalls - Read data: %d %lf %lf %lf %lf\n", bl.ballNum, bl.X, bl.Y, bl.Vx, bl.Vy);

        /* Add ball to linked list */
        bl.table = table;
        addBall(&bl);
    }

    return scanVal;
}

/* Read balls and run simulation if necessary */
void attemptSim(struct Sim *table) {

    /* Read balls */
    int scanVal = readBalls(table);
    if (TEXT) printf("scanf returned %d\n", scanVal);

    /* No need to run sim if no balls are read in */
    if (table->head == NULL) return;

    /* Initialize graphics if necessary, ending program if graphics fail */
    if (GRAPHICS && !eb_initialize(0)) return;

    /* Run simulation */
    runSim(table);

    /* Tear down graphics if necessary */
    if (GRAPHICS) eb_teardown();
}

/* Run sim and record total runtime */
int main() {

    /* Create sim and start total runtime */
    double start = now();
    struct Sim table = {0.0, DEFAULT_DT, NULL};

    /* Read balls and run simulation */
    attemptSim(&table);

    /* Print final runtime */
    printf("Total run time is %11.9lf seconds.\n", (now() - start));

    return 0;
}

