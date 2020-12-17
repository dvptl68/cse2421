/* Dev Patel */

#include <stdio.h>
#include "lib8ball.h"
#include "linkedlist.h"
#include "structs.h"
#include "output.h"
#include "debug.h"

/* Action function to output ball in text mode */
void printBall(void *data) {

    /* Set ball struct to make usage less of an eyesore */
    struct Ball *bl = (struct Ball *)data;

    printf("Ball #%2d is at (%6.3lf, %6.3lf) moving (%9.4lf, %9.4lf)\n", bl->ballNum, bl->X, bl->Y, bl->Vx, bl->Vy);
}

/* Print all ball data */
void printAllData(struct Sim *table) {

    printf("\nAt time %7.4lf:\n", table->elapsed);
    iterate(table->head, &printBall);
}

/* Action function to draw ball */
void displayBall(void *data) {

    /* Set ball struct to make usage less of an eyesore */
    struct Ball *bl = (struct Ball *)data;

    eb_ball(bl->ballNum, bl->X, bl->Y);
}

/* Output all balls to graphical display */
void drawAllData(struct Sim *table) {

    /* Clear current screen, draw ball and refresh */
    eb_clear();
    iterate(table->head, &displayBall);
    eb_refresh();

    /* Stop execution for calculated time */
    millisleep((unsigned int)(table->dT * CONVERSION));
}

/* Display data during simulation */
void updateOutput(struct Sim *table) {

    if (TEXT) printAllData(table);
    if (GRAPHICS) drawAllData(table);
}

/* Print end of simulation */
void outputEnd(double elapsed) {

    printf("\nSimulation ends at sim elapsed time of %7.4lf seconds.\n", elapsed);
}

