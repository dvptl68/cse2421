# Dev Patel

# All dependencies
all: prototypes lab2 lab2.zip clean

# Create program executable
lab2: lab2.o table.o output.o
	gcc -ansi -pedantic -g -o $@ $^ -lncurses -L. -l8ball

# PLEASE GRADE: First prototype - code to learn and practice using printf and scanf
ioPro: ioPro.o
	gcc -ansi -pedantic -g -o $@ $^ -lncurses -L. -l8ball

# PLEASE GRADE: Second prototype - function to check if the ball is off the table
offTablePro: offTablePro.o
	gcc -ansi -pedantic -g -o $@ $^ -lncurses -L. -l8ball

# PLEASE GRADE: Third prototype - function to calculate delta T
deltaTPro: deltaTPro.o
	gcc -ansi -pedantic -g -o $@ $^ -lncurses -L. -l8ball

# PLEASE GRADE: Fourth prototype - function to print ball simulation data correctly
outputPro: outputPro.c
	gcc -ansi -pedantic -g -o $@ $^ -lncurses -L. -l8ball

# Rule to make all prototypes
prototypes: ioPro offTablePro deltaTPro outputPro

# Generic rule to convert .c files into .o files when there are .h files
%.o: %.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# Build zip file
lab2.zip: makefile
	zip $@ README_LAB2 makefile *.c *.h *.a

# Generate tags and headers
tags: *.c
	ctags -R .

headers: *.c tags
	headers.sh

# Clean unneeded files
clean:
	rm -f *.o

