# Dev Patel

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT 
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS.I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

# Directives
.file "evaluate.s"
.section .rodata

# Strings needed to print
.LC0:
    .string "evaluate: using range %d to evaluate \"%s\".\n"

.LC1:
    .string "evaluate: found %d words in \"%s\" using range %d.\n"

.data
.align 8

# Evaluate function
.globl evaluate
    .type evaluate, @function
.text
evaluate:

    pushq %rbp # save caller rbp
    movq %rsp, %rbp # set function frame pointer

    pushq %r12 # r12 stores the input pointer to char
    pushq %r13 # r13 stores range number
    pushq %r14 # r14 stores the word count

    movq %rdi, %r12 # save input pointer to char to r12
    movq %rsi, %r13 # save range number to r13

    movq %rdi, %rdx # set third parameter to the input pointer to char
    movq $.LC0, %rdi # set first parameter to print string
    xorq %rax, %rax # clear rax before function call
    call print # print information - second parameter stays the same

    movq %r12, %rdi # set first parameter to the input pointer to char
    movq %r13, %rsi # set second paramter to range number
    xorq %rax, %rax # clear rax before function call
    call count # get word count
    movq %rax, %r14 # save word count return value

    movq $.LC1, %rdi # set first parameter to print string
    movq %r14, %rsi # set second parameter to word count
    movq %r12, %rdx # set third paramter to input pointer to char
    movq %r13, %rcx # set fourth parameter to range number
    xorq %rax, %rax # clear rax before function call
    call print # print information

    movq %r14, %rax # set return value to word count

    popq %r14 # restore original r14
    popq %r13 # restore original r13
    popq %r12 # restore original r12

    leave # tear down stack frame
    ret

.size evaluate, .-evaluate

