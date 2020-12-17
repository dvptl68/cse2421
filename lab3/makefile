# Dev Patel

# All dependencies
all: lab3 prototypes clean

# Create program executable
lab3: lab3.o output.o table.o allocate.o movement.o
	gcc -g -o $@ $^ -L. -l8ball -llinkedlist -lncurses -lm

test: test.o
	gcc -g -o $@ $^
# PLEASE GRADE: First prototype - test frictional computation
frictionPro: frictionPro.o 
	gcc -g -o $@ $^ -L. -l8ball -llinkedlist -lncurses -lm

# PLEASE GRADE: Second prototype - test bouncing off rails
reflectPro: reflectPro.o
	gcc -g -o $@ $^ -L. -l8ball -llinkedlist -lncurses -lm

# PLEASE GRADE: Third prototype - test function pointers for linked list
listFunctionsPro: listFunctionsPro.o
	gcc -g -o $@ $^ -L. -l8ball -llinkedlist -lncurses -lm

# PLEASE GRADE: Fourth prototype - test using list functions
listPro: listPro.o
	gcc -g -o $@ $^ -L. -l8ball -llinkedlist -lncurses -lm

# Rule to make all prototypes
prototypes: frictionPro reflectPro listFunctionsPro listPro

# Generic rule to convert .c files into .o files when there are .h files
%.o: %.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# Build zip file
lab3.zip: makefile README* *.c *.h *.a
	zip $@ $^
	# Test zip file
	rm -rf testZip
	mkdir testZip
	unzip $@ -d testZip
	cp 1ball testZip
	cp 16balls testZip
	cp 16set testZip
	cp vshot testZip

# Generate tags and headers
tags: *.c
	ctags -R .

headers: *.c tags
	headers.sh

# Clean unneeded files
clean:
	rm -f *.o

