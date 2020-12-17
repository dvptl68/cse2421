/* Dev Patel */

#include <stdio.h>
#include "debug.h"
#include "lib8ball.h"
#include "output.h"

/* Output start of simulation */
void outputStart(int ballNum) {

    if (TEXT) printf("Lab 2 starting ball %d\n", ballNum);
}

/* Output ball in text mode */
void printBall(int ballNum, double xPos, double yPos, double totalTime) {

    printf("At time %7.3lf Ball #%2d is at (%6.3lf, %6.3lf)\n", totalTime, ballNum, xPos, yPos);
}

/* Output ball in graphics mode */
void drawBall(int ballNum, double xPos, double yPos, double dT) {

    /* Clear current screen, draw ball and refresh */
    eb_clear();
    eb_ball(ballNum, xPos, yPos);
    eb_refresh();

    /* Stop execution for calculated time */
    millisleep((unsigned int)(dT * CONVERSION));
}

/* Output movement of simulation */
void outputBall(int ballNum, double xPos, double yPos, double totalTime, double dT) {

    if (TEXT) printBall(ballNum, xPos, yPos, totalTime);
    if (GRAPHICS) drawBall(ballNum, xPos, yPos, dT);
}

/* Output end in text mode */
void printEnd(int ballNum, double xPos, double yPos, double totalTime) {

    printf("Ball #%2d is off the table at (%.3lf, %.3lf) at time %7.3lf\n", ballNum, xPos, yPos, totalTime);
}

/* Output end in graphics mode */
void drawEnd() {

    eb_clear();
    eb_refresh();
    millisleep((unsigned int) SLEEP);
}

/* Output end of simulation */
void outputEnd(int ballNum, double xPos, double yPos, double totalTime) {

    if (TEXT) printEnd(ballNum, xPos, yPos, totalTime);
    if (GRAPHICS) drawEnd();
}

