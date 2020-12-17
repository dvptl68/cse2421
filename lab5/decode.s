# Dev Patel

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT 
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS.I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

# Directives
.file "decode.s"
.section .rodata
.data
.align 8

# Arrays to hold valid codes and their decoded nibble values
validCodes:
    .quad 0x19
    .quad 0x1b
    .quad 0x12
    .quad 0x13
    .quad 0x1d
    .quad 0x15
    .quad 0x16
    .quad 0x17
    .quad 0x1a
    .quad 0x09
    .quad 0x0a
    .quad 0x0b
    .quad 0x1e
    .quad 0x0d
    .quad 0x0e
    .quad 0x0f

# Decode function
.globl decode_nibble
    .type decode_nibble, @function
.text
decode_nibble:

    pushq %rbp # save caller rbp
    movq %rsp, %rbp # set function frame pointer

    movq $validCodes, %rdx # rdx is a pointer to the first element of validCodes array
    movq $15, %rsi # rsi is the loop counter and also serves as the decoded value
    movq $0xff, %rax # rax is the decoded nibble and return value

decode_loop:

    cmpq (%rdx, %rsi, 8), %rdi # compare the current code to the parameter rdi
    cmove %rsi, %rax # set rax to decoded value if the code matches
    decq %rsi # decrement loop counter
    jns decode_loop # jump to start of loop if it is not out of range

    leave # tear down stack frame
    ret
    .size decode_nibble, .-decode_nibble

