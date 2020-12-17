# Dev Patel

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT 
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS.I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

# Directives
.file "search.s"
.section .rodata

# String needed to print
.LC0:
    .string "search: \"%s\" has the most words using range %d with %d found.\n"

.data
.align 8

# Search function
.globl search
    .type search, @function
.text
search:

    pushq %rbp # save caller rbp
    movq %rsp, %rbp # set function frame pointer

    pushq %r12 # r12 is the best count
    pushq %r13 # r13 is the pointer to the string with the best count
    pushq %r14 # r14 is the range number
    pushq %rbx # rbx is a pointer to the string array

    movq $-1, %r12 # original best count is -1
    xorq %r13, %r13 # original best pointer is null
    movq %rdx, %r14 # save range number to r14
    movq %rdi, %rbx # save string array pointer to rbx

get_counts:

    movq (%rbx), %rdi #  place string pointer in first parameter register

    testq %rdi, %rdi # check if current pointer is null
    je done # jump to end of function if current pointer is null

    movq %r14, %rsi # set second parameter to range number
    xorq %rax, %rax # clear rax before function call
    call evaluate # get word count of given string

    cmpq %r12, %rax # compare current word count to best word count
    cmovg %rax, %r12 # set new best count if needed
    cmovg (%rbx), %r13 # set new pointer to string with best count if needed

    addq $8, %rbx # go to next string in array
    jmp get_counts

done:

    movq $.LC0, %rdi # set first parameter to print string
    movq %r13, %rsi # set second parameter to string with best count
    movq %r14, %rdx # set third parameter to range number
    movq %r12, %rcx # set fourth parameter to best word count
    xorq %rax, %rax # clear rax before function call
    call print # print final information

    movq %r13, %rax # set return value to string with best word count

    popq %rbx # restore original rbx
    popq %r14 # restore original r14
    popq %r13 # restore original r13
    popq %r12 # restore original r12

    leave # tear down stack frame
    ret

.size search, .-search

