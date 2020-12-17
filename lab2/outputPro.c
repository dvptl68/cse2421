/* Dev Patel */
/* Prototype to print the ball data */

#include <stdio.h>

/* Output ball in text mode */
void printBall(int ballNum, double xPos, double yPos, double totalTime) {

    printf("At time %7.3lf Ball #%2d is at (%6.3lf, %6.3lf)\n", totalTime, ballNum, xPos, yPos);
}

int main() {

    /* Variable declarations */
    int i;
    double xPos = 0.0, yPos = 0.0, totalTime = 0.0;

    /* Loop to call print function with different values */
    for (i = 0; i < 200; i++){

        printBall(8, xPos, yPos, totalTime);
        xPos += 0.578324;
        yPos += 0.093205;
        totalTime += 1.1;
    }

    return 0;
}

