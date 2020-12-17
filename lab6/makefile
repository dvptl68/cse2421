# AU20 Lab 6 makefile Copyright 2020 Neil Kirby Do not remove this comment
# Dev Patel

all: count evaluate lab6 lab6Bonus

# Create lab 6 executable using Assembly main function - Bonus A
lab6Bonus: lab6main.s search.s evaluate.s count.s 
	gcc -g -m64 -o lab6Bonus lab6main.s print.o count.s evaluate.s search.s

# Create lab 6 executable using given C code
lab6: lab6main.o search.s evaluate.s count.s 
	gcc -g -m64 -o lab6 lab6main.o print.o count.s evaluate.s search.s

# Create evaluate executable
evaluate: evalmain.o count.s evaluate.s
	gcc -g -m64 -o evaluate evalmain.o print.o count.s evaluate.s

# Create count executable
count: countmain.o count.s
	gcc -g -m64 -o count countmain.o print.o count.s

# Create lab 6 zip file
lab6.zip: *.c *.h *.s print.o README* makefile
	zip $@ $^

# Generic rule to convert .c files into .o files when there are .h files
%.o: %.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

