/* Dev Patel */

#include <stdio.h>
#include "include.h"

int multiplyBy2(int x) {

	return 2 * x;
}

int main() {

	int i = INIT, j;
	
	printf("Before, i=%d\n", i);
	j = multiplyBy2(i);
	printf("After, j=%d\n", j);
	/* Returning 0 to the system signifies no errors */
	return 0;
}

