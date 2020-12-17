/* Dev Patel */
/* Prototype to test computation of velocity with friction */

#include <stdio.h>
#include <math.h>
#define DEBUG 0

/* Calculates the percent change in velocity that friction will incur */
double frictionPercent(double Vx, double Vy, double dT) {

    /* Declarations and calculations */
    double dV, V;

    dV = 0.01 * 386.08858267716 * dT;
    V = sqrt((Vx * Vx) + (Vy * Vy));

    if (DEBUG) printf("frictionPercent - dV: %lf, V: %lf\n", dV, V);

    return dV / V;
}

/* Apply friction change to overall velocity */
void applyFriction(double *Vx, double *Vy, double change) {

    *Vx *= (1 - change);
    *Vy *= (1 - change);
}

int main() {

    double VxTemp, VyTemp, VxOrig, VyOrig;
    double Vx[5] = {100, 200, -50, 25, 0};
    double Vy[5] = {50, -75, 200, 0, 100};
    double dT = 0.1;
    int i;

    for (i = 0; i < 5; i++) {
        VxOrig = VxTemp = Vx[i], VyOrig = VyTemp = Vy[i];
        applyFriction(&VxTemp, &VyTemp, frictionPercent(VxTemp, VyTemp, dT));
        printf("Vx: %.1lf, Vy: %.1lf, dT: 0.1, Percent: %lf, New Vx: %lf, New Vy: %lf\n", VxOrig, VyOrig, frictionPercent(VxTemp, VyTemp, dT), VxTemp, VyTemp);
    }

    return 0;
}

