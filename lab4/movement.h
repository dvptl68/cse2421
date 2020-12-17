/* Dev Patel */

/* Constants */
#define MU 0.01 /* Coefficient of friction */
#define G_IPS2 386.08858267716 /* Gravity in in/s^2 */
#define RADIUS 1.125 /* Radius of balls */

/* Function prototypes */
double ballDT(void *data);
void moveBall(void *data);
void applyFriction(void *data);

