/* Dev Patel */

#include <stdio.h>
#include "lab2.h"
#include "debug.h"
#include "table.h"
#include "output.h"
#include "lib8ball.h"

/* Runs simulation given original input */
void runSim(int ballNum, double xPos, double yPos, double Vx, double Vy) {

    /* Variable declarations */
    double dT, totalTime = 0;

    outputStart(ballNum);

    /* Simulate until the ball is off the table */
    while (!offTable(xPos, yPos)){

        /* Get smallest dT */
        dT = deltaT(deltaT(DEFAULTDT, Vx), Vy);

        /* Output current ball position and time */
        outputBall(ballNum, xPos, yPos, totalTime, dT);

        /* Increase total time */
        totalTime += dT;

        if (DEBUG) printf("Total time: %lf", totalTime);

        /* Calculate new position */
        xPos = (xPos + (Vx * dT));
        yPos = (yPos + (Vy * dT));
    }
    
    outputEnd(ballNum, xPos, yPos, totalTime);
}

/* Handles input and calls functions accordingly */
int main() {

    /* Variable declarations */
    int ballNum, scanVal;
    double xPos, yPos, Vx, Vy, start = now();

    /* Initialize graphics if necessary */
    if (GRAPHICS && !eb_initialize(0)) return 0;

    /* Scan ball input and terminate with invalid input */
    while ((scanVal = scanf("%d %lf %lf %lf %lf", &ballNum, &xPos, &yPos, &Vx, &Vy)) == 5){

        if (DEBUG) printf("%d %lf %lf %lf %lf\n", ballNum, xPos, yPos, Vx, Vy);

        /* Run simulation for each ball */
        runSim(ballNum, xPos, yPos, Vx, Vy);
    }

    /* Tear down graphics if necessary */
    if (GRAPHICS) eb_teardown();

    /* Print final data */
    printf("Ending: scanf returned %d\nTotal run time is %lf seconds.\n", scanVal, (now() - start));

    return 0;
}

