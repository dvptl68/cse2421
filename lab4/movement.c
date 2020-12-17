/* Dev Patel */

#include <stdio.h>
#include <math.h>
#include "movement.h"
#include "structs.h"
#include "debug.h"

/* Computes and returns delta T given the velocity of the ball */
double deltaT(double currentTime, double velocity) {

    /* Variable declaration */
    double newTime;

    if (DEBUG) printf("deltaT - Velocity is: %lf\n", velocity);

    /* Return passed in time if velocity is 0 to avoid illegal division */
    if (velocity == 0.0) return currentTime;

    /* Calculate new time, making it positive if necessary */
    newTime = 0.5 * RADIUS / velocity;
    if (DEBUG) printf("deltaT - New time before adjustment: %lf\n", newTime);
    if (newTime < 0.0) newTime *= -1;
    if (DEBUG) printf("deltaT - New time after adjustment: %lf\n", newTime);

    /* Return the smaller time */
    if (DEBUG) printf("deltaT - New time: %lf; Passed-in time: %lf\n", newTime, currentTime);
    if (newTime < currentTime) return newTime;
    return currentTime;
}

/* Finds minimum dT given a void pointer to a ball */
double ballDT(void *data) {

    /* Set ball struct to make usage less of an eyesore */
    struct Ball *bl = (struct Ball *)data;

    /* Find lowest dT */
    return deltaT(deltaT(bl->table->dT, bl->Vx), bl->Vy);
}

/* Moves ball to next position */
void moveBall(void *data) {

    /* Set ball struct to make usage less of an eyesore */
    struct Ball *bl = (struct Ball *)data;

    /* Move ball's X position */
    bl->X = bl->X + ((bl->Vx) * (bl->table->dT));

    /* Move ball's Y position */
    bl->Y = bl->Y + ((bl->Vy) * (bl->table->dT));

    if (DEBUG) printf("moveBall - X: %lf, Y: %lf\n", bl->X, bl->Y);
}

/* Calculates the percent change in velocity that friction will incur */
double frictionPercent(struct Ball *bl) {

    /* Declarations and frictional calculations */
    double dV, V;

    dV = MU * G_IPS2 * (bl->table->dT);
    V = sqrt((bl->Vx * bl->Vx) + (bl->Vy * bl->Vy));

    if (DEBUG) printf("frictionPercent - dV: %lf, V: %lf\n", dV, V);

    /* Check if the ball needs to stop */
    return (dV >= V) ? 1 : (dV / V);
}

/* Apply friction on ball */
void applyFriction(void *data) {

    double percent;

    /* Set ball struct to make usage less of an eyesore */
    struct Ball *bl = (struct Ball *)data;

    /* Get friction percentage */
    percent = frictionPercent(bl);

    /* Apply friction velocity change */
    bl->Vx *= (1 - percent);
    bl->Vy *= (1 - percent);

    if (DEBUG) printf("applyFriction - Vx: %lf, Vy: %lf\n", bl->Vx, bl->Vy);
}

