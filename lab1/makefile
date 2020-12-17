# Dev Patel

#change the last dependency for each new lab
all:  tags headers lab1 stuff lab1.zip

#this entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

lab1: lab1.o 
	gcc -g -o $@ $^ 

#this is where you create an entry to build yuour zip file
#it will also update with new labs



#this entry stays for C code labs
tags: *.c
	ctags -R .

# this entry stays for C code labs
headers: *.c tags
	headers.sh


# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# adds useful compilation information into a file called "stuff"
stuff: makefile
	date > stuff
	ls -lt >> stuff

# creates zip file for submission to Carmen
lab1.zip: makefile *.c *.h README_LAB1
	zip lab1.zip makefile *.c *.h README_LAB1
