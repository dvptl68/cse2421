/* Dev Patel */
/* Prototype to check if ball is off the table or not */

#include <stdio.h>
#include "debug.h"
#include "dimensions.h"

/* Returns 0 if the ball is on the table, an arbitrary int otherwise */
int offTable(double x, double y) {

	if (DEBUG) printf("X position is %lf. Out of range? %d\n", x, x < 0.0 || x >= LENGTH);
	if (DEBUG) printf("Y position is %lf. Out of range? %d\n", y, y < 0.0 || y >= WIDTH);

	return (x < 0.0) || (x >= LENGTH) || (y < 0.0) || (y >= WIDTH);
}

int main() {

	/* Values to be tested */
	double X[6] = {50.0, -10.0, 105.34, 50.0, 50.0, 103.2};
	double Y[6] = {25.0, 25.0, 25.0, -5.648, 53.29, -7.0};
	int expected[6] = {0, 1, 1, 1, 1, 1};
	int actual;
	int i;

	/* Test each value and print result */
	for (i = 0; i < 6; i++){

		actual = offTable(X[i], Y[i]);

		/* Check if returned value matches expected value and print result */
		if ((expected[i] == 0 && actual == 0) || (expected[i] == 1 && actual != 0)) {
			printf("Test %d passed.\n", i+1);
		}else{
			printf("Test %d failed.\n", i+1);
		}
	}

	return 0;
}

