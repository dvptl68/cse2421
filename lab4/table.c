/* Dev Patel */

#include <stdio.h>
#include "structs.h"
#include "debug.h"
#include "dimensions.h"
#include "table.h"

/* Reflect off top wall */
void reflectTop(struct Ball *bl) {

    /* Reflect ball away from wall based on how far over the rail it is */
    bl->Y = (WIDTH - ((bl->Y + RADIUS) - WIDTH)) - RADIUS;

    /* Reduce velocities in half, flipping Vy */
    bl->Vx *= 1.0 / 2.0;
    bl->Vy *= -1.0 / 2.0;

    if (DEBUG) printf("reflectTop - Y: %lf, Vx: %lf, Vy: %lf\n", bl->Y, bl->Vx, bl->Vy);
}

/* Reflect off bottom wall */
void reflectBottom(struct Ball *bl) {

    /* Reflect ball away from wall based on how far over the rail it is */
    bl->Y = (0 - (bl->Y - RADIUS)) + RADIUS;

    /* Reduce velocities in half, flipping Vy */
    bl->Vx *= 1.0 / 2.0;
    bl->Vy *= -1.0 / 2.0;

    if (DEBUG) printf("reflectBottom - Y: %lf, Vx: %lf, Vy: %lf\n", bl->Y, bl->Vx, bl->Vy);
}

/* Reflect off right wall */
void reflectRight(struct Ball *bl) {

    /* Reflect ball away from wall based on how far over the rail it is */
    bl->X = (LENGTH - ((bl->X + RADIUS) - LENGTH)) - RADIUS;

    /* Reduce velocities in half, flipping Vx */
    bl->Vx *= -1.0 / 2.0;
    bl->Vy *= 1.0 / 2.0;

    if (DEBUG) printf("reflectRight - X: %lf, Vx: %lf, Vy: %lf\n", bl->X, bl->Vx, bl->Vy);
}

/* Reflect off left wall */
void reflectLeft(struct Ball *bl) {

    /* Reflect ball away from wall based on how far over the rail it is */
    bl->X = (0 - (bl->X - RADIUS)) + RADIUS;

    /* Reduce velocities in half, flipping Vx */
    bl->Vx *= -1.0 / 2.0;
    bl->Vy *= 1.0 / 2.0;

    if (DEBUG) printf("reflectLeft - X: %lf, Vx: %lf, Vy: %lf\n", bl->X, bl->Vx, bl->Vy);
}

/* Checks if ball is headed toward an X pocket */
int checkXPocket(double X) {
    return (X < CORNER_POCKET) || (X > LENGTH - CORNER_POCKET) || (X > X_POCKET_START && X < X_POCKET_END);
}

/* Checks if ball is headed toward a Y pocket */
int checkYPocket(double Y) {
    return (Y < CORNER_POCKET) || (Y > WIDTH - CORNER_POCKET);
}

/* Action function to reflect the ball if necessary */
void reflectBall(void *data) {

    /* Set ball struct to make usage less of an eyesore */
    struct Ball *bl = (struct Ball *)data;

	if (DEBUG) printf("reflectBall - Ball %d X position is (%lf, %lf)\n", bl->ballNum, bl->X, bl->Y);

    /* Reflect off a given wall if ball is on a rail and not headed to a pocket */
    if (((bl->X - RADIUS) < 0.0) && !checkYPocket(bl->Y)) reflectLeft(bl);
    else if (((bl->X + RADIUS) >= LENGTH) && !checkYPocket(bl->Y)) reflectRight(bl);
    else if (((bl->Y - RADIUS) < 0.0) && !checkXPocket(bl->X)) reflectBottom(bl);
    else if (((bl->Y + RADIUS) >= WIDTH) && !checkXPocket(bl->X)) reflectTop(bl);
}

/* Criteria function for deleting balls that are in pockets */
int inPocket(void *data) {

    /* Set ball struct to make usage less of an eyesore */
    struct Ball *bl = (struct Ball *)data;

    if (DEBUG) printf("inPocket - Ball %d X position is (%lf, %lf)\n", bl->ballNum, bl->X, bl->Y);

    /* Check side pockets if ball is on a side wall, otherwise check top and bottom pockets */
    if (bl->X - RADIUS < 0.0 || bl->X + RADIUS >= LENGTH){

        /* If ball is headed toward a Y pocket, check if it has fallen in */
        if (checkYPocket(bl->Y)) return ((bl->X < 0.0) || (bl->X > LENGTH));

    }else if (bl->Y - RADIUS < 0.0 || bl->Y + RADIUS >= WIDTH){

        /* If ball is headed toward an X pocket, check if it has fallen in */
        if (checkXPocket(bl->X)) return ((bl->Y < 0.0) || (bl->Y > WIDTH));
    }

    return 0;
}

