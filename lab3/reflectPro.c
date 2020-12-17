/* Dev Patel */
/* Prototype to test ball bouncing off rails */

#include <stdio.h>
#include "dimensions.h"

/* Reflect off a wall - top wall for testing purposes */
void reflectTop(double *X, double *Y, double *Vx, double *Vy) {

    /* Reflect ball away from wall based on how far over the rail it is */
    *Y = (WIDTH - ((*Y + RADIUS) - WIDTH)) - RADIUS;

    /* Reduce velocities in half, flipping Vy */
    *Vx *= 1.0 / 2.0;
    *Vy *= -1.0 / 2.0;
}

int main() {

    double X[5] = {90, 75, 35};
    double Y[5] = {50 - RADIUS / 8, 50 - RADIUS / 5, 50 - RADIUS / 3};
    double Vx[5] = {50, 30, -10};
    double Vy[5] = {45, -95, 60};
    int i;

    for (i = 0; i < 3; i++) {
        printf("Test %d:\nOriginal - X: %lf, Y: %lf, Vx: %lf, Vy: %lf\n", i + 1, X[i], Y[i], Vx[i], Vy[i]);
        reflectTop(&X[i], &Y[i], &Vx[i], &Vy[i]);
        printf("Reflected - X: %lf, Y: %lf, Vx: %lf, Vy: %lf\n", X[i], Y[i], Vx[i], Vy[i]);
    }

    return 0;
}

