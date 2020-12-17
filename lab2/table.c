/* Dev Patel */

#include <stdio.h>
#include "debug.h"
#include "dimensions.h"
#include "table.h"

/* Returns 0 if the ball is on the table, an arbitrary int otherwise */
int offTable(double x, double y) {

	if (DEBUG) printf("X position is %lf. Out of range? %d\n", x, x < 0.0 || x >= LENGTH);
	if (DEBUG) printf("Y position is %lf. Out of range? %d\n", y, y < 0.0 || y >= WIDTH);

	return (x < 0.0) || (x >= LENGTH) || (y < 0.0) || (y >= WIDTH);
}

/* Computes and returns delta T given the velocity of the ball */
double deltaT(double currentTime, double velocity) {

    /* Variable declaration */
    double newTime;

    if (DEBUG) printf("Velocity is: %lf\n", velocity);

    /* Return passed in time if velocity is 0 to avoid illegal division */
    if (velocity == 0.0) return currentTime;

    /* Calculate new time, making it positive if necessary */
    newTime = 0.5 * RADIUS / velocity;
    if (DEBUG) printf("New time before adjustment: %lf\n", newTime);
    if (newTime < 0.0) newTime *= -1;
    if (DEBUG) printf("New time after adjustment: %lf\n", newTime);

    /* Return the smaller time */
    if (DEBUG) printf("New time: %lf; Passed-in time: %lf\n", newTime, currentTime);
    if (newTime < currentTime) return newTime;
    return currentTime;
}

