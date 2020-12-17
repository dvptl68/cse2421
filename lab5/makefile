
# AU20 Lab 5 makefile Copyright 2020 Neil Kirby Do not remove this comment
# Dev Patel

all: lab5 nibble_test 

# Create nibble_test executable
nibble_test: decode.s nibble_test.o
	gcc -m64 -g -o $@ $^ 

# Create lab 5 executable
lab5: decode.s gcr.s lab5.o
	gcc -m64 -g -o $@ $^ 

# Build zip file
lab5.zip : makefile README* *.s *.o
	zip $@ $^
