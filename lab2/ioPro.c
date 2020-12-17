/* Dev Patel */
/* Prototype to test scanf and printf */

#include <stdio.h>

/* Prints simple greeting based on parameters */
void greet(int age) {

	printf("Hi user! Welcome to lab 2. The age of %d is the perfect age to be testing prototypes at!\n", age);
}


int main() {

	/* Variable declaration */
    int age;

	/* Prompt user to enter name and age */
	printf("Enter your age: ");
	scanf("%d", &age);

	/* Call function to greet tester */
	greet(age);

	return 0;
}

