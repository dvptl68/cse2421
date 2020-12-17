# Dev Patel

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT 
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS.I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

# Directives
.file "lab6main.s"
.section .rodata

# All strings to be tested
.LC0:  .string "FIRST STRING IN THE LIST."
.LC1:  .string "That's all folks!"
.LC2:  .string "Let's be careful out there."
.LC3:  .string "395 Dreese Labs, 2015 Neil Avenue, COlumbus, OH, 43210"
.LC4:  .string "Well, to tell you the truth, in all this excitement I kind of lost track myself."
.LC5:  .string "And gentlemen in England now a-bed shall think themselves accursed that they were not here!"
.LC6:  .string "Use The Force, Luke!"
.LC7:  .string "C is call by value."
.LC8:  .string "O-H!"
.LC9:  .string "I-O!"
.LC10:  .string "Go Bucks!"
.LC11: .string ""
.LC12: .string "I don't know about you but I just found /* inside a comment."
.LC13: .string "3 to beam up."
.LC14: .string "We few, we hapy few, we band of programmers;"
.LC15: .string "8 6 7 5 3 0 9 (Sorry if that got stuck in your head)"
.LC16: .string "4 I In thIs strIng."
.LC17: .string "THAT FOUGHT WITH US UPON SAINT CRISPIN'S DAY!"
.LC18: .string "https://en.wikipedia.org/wiki/St_Crispin%27s_Day_Speech"
.LC19: .string "https://www.youtube.com/watch?v=bvFHRNGYfuo"
.LC20: .string "last string in the list."

# Strings needed to print
.LC21:
    .string "The last string is %s\n"
.LC22:
    .string "Lab6: '%s' has the most words using range %d'\n\n"

# Define strings array
strings:
    .quad .LC0
    .quad .LC1
    .quad .LC2
    .quad .LC3
    .quad .LC4
    .quad .LC5
    .quad .LC6
    .quad .LC7
    .quad .LC8
    .quad .LC9
    .quad .LC10
    .quad .LC11
    .quad .LC12
    .quad .LC13
    .quad .LC14
    .quad .LC15
    .quad .LC16
    .quad .LC17
    .quad .LC18
    .quad .LC19
    .quad .LC20
    .quad 0

.data
.align 8

# Main function
.globl main
    .type main, @function
.text
main:

    pushq %rbp # save caller rbp
    movq %rsp, %rbp # set function frame pointer

    pushq %r12 # r12 is the loop counter and range number
    pushq %r13 # r13 is the size of the string array
    pushq %r14 # r14 holds a pointer to the string array

    xorq %r12, %r12 # set loop counter to 0
    movq $21, %r13 # set r13 to the array size
    movq $strings, %r14 # set r14 to point to the strings array

    movq $.LC21, %rdi # set first parameter to print string
    movq -8(%r14, %r13, 8), %rsi # set second parameter to last string in array
    xorq %rax, %rax # clear rax before function call
    call print # print last string in array

search_ranges:

    movq %r14, %rdi # set first parameter to string array
    movq %r13, %rsi # set second parameter to size of string array
    movq %r12, %rdx # set third parameter to range number
    xorq %rax, %rax # clear rax before function call
    call search # find string with most words with given range

    movq $.LC22, %rdi # set first parameter to print string
    movq %rax, %rsi # set second parameter to string with best count
    movq %r12, %rdx # set third parameter to range number
    xorq %rax, %rax # clear rax before function call
    call print # print string with best word count and range number

    incb %r12b # increment loop counter
    cmpb $3, %r12b # compare loop counter to stopping point
    jb search_ranges # go back to start of loop if counter is still in range

    xorq %rax, %rax # set rax to 0 to indicate successful exit

    popq %r14 # restore original r14
    popq %r13 # restore original r13
    popq %r12 # restore original r12

    leave # tear down stack frame
    ret

.size main, .-main

