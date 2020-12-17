# Dev Patel

# All dependencies
all: lab4 lab4u prototypes clean

# Create reliable program executable
lab4: lab4.o output.o table.o allocate.o movement.o linkedlist.o reliable.o
	gcc -g -o $@ $^ -L. -l8ball -lncurses -lm

# Create unreliable program executable
lab4u: lab4.o output.o table.o allocate.o movement.o linkedlist.o unreliable.o
	gcc -g -o $@ $^ -L. -l8ball -lncurses -lm

# PLEASE GRADE: First prototype - test file input and command line arguments
filePro: filePro.o
	gcc -g -o $@ $^

# PLEASE GRADE: Second prototype - test using the unreliable allocation library
allocPro: allocPro.o unreliable.o
	gcc -g -o $@ $^

# PLEASE GRADE: Third prototype - test iterate function for the linked list
iteratePro: iteratePro.o
	gcc -g -o $@ $^ -L. -llinkedlist

# PLEASE GRADE: Fourth prototype - test deleteSome function for the linked list
deletePro: deletePro.o
	gcc -g -o $@ $^ -L. -llinkedlist

# Rule to make all prototypes
prototypes: *Pro

# Generic rule to convert .c files into .o files when there are .h files
%.o: %.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# Build zip file
lab4.zip: makefile README* *.c *.h *.a *.o
	zip $@ $^

# Generate tags and headers
tags: *.c
	ctags -R .

headers: *.c tags
	headers.sh

# Clean unneeded files
clean:
	rm -f lab4.o output.o table.o allocate.o movement.o linkedlist.o *Pro.o

