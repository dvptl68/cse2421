/* Dev Patel */
/* Prototype to test the computation of delta T */

#include <stdio.h>
#include "debug.h"
#include "dimensions.h"

/* Computes and returns delta T given the velocity of the ball */
double deltaT(double currentTime, double velocity) {

    /* Variable declaration */
    double newTime;

    if (DEBUG) printf("Velocity is: %lf\n", velocity);

    /* Return passed in time if velocity is 0 to avoid illegal division */
    if (velocity == 0.0) return currentTime;

    /* Calculate new time, making it positive if necessary */
    newTime = 0.5 * RADIUS / velocity;
    if(DEBUG) printf("New time before adjustment: %lf\n", newTime);
    if (newTime < 0.0) newTime *= -1;
    if(DEBUG) printf("New time after adjustment: %lf\n", newTime);

    /* Return the smaller time */
    if(DEBUG) printf("New time: %lf; Passed-in time: %lf\n", newTime, currentTime);
    if (newTime < currentTime) return newTime;
    return currentTime;
}

int main() {

    /* Tests for deltaT prototype */
    printf("Delta T for a velocity of %0.1lf in/s: %0.3lf\n", 1.0, deltaT(0.1, 1.0));
    printf("Delta T for a velocity of %0.1lf in/s: %0.3lf\n", 2.5, deltaT(0.1, 2.5));
    printf("Delta T for a velocity of %0.1lf in/s: %0.3lf\n", -50.0, deltaT(0.1, -50.0));
    printf("Delta T for a velocity of %0.1lf in/s: %0.3lf\n", 50.0, deltaT(0.1, 50.0));
    printf("Delta T for an X velocity of %0.1lf in/s and Y velocity of %0.1lf in/s: %0.3lf\n", 2.5, -50.0, deltaT(deltaT(0.1, -50.0), 1.0));

    return 0;
}

