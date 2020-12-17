# Dev Patel

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT 
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS.I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

# Directives
.file "gcr.s"
.section .rodata
.data
.align 8

# GCR function
.globl fromGCR
    .type fromGCR, @function
.text
fromGCR:

    pushq %rbp # save caller rbp
    movq %rsp, %rbp # set function frame pointer

    # Save all used registers
    pushq %r12
    pushq %r13
    pushq %r14

    xorq %r12, %r12 # r12 is the loop counter
    movq %rdi, %r13 # r13 holds the input
    xorq %rdi, %rdi # zero rdi for parameter use for function calls
    xorq %r14, %r14 # r14 holds the output

get_nibbles:

    movb %r13b, %dil # copy lowest byte of input to lowest byte of rdi
    shrq $5, %r13 # shift input right 5 bits
    andb $31, %dil # clear upper 3 bits of lowest byte of rdi (00011111 binary = 31 decimal)

    xorq %rax, %rax # zero rax before function call for ABI
    call decode_nibble # get decoded nibble value

    cmpq $0xFF, %rax # compare rax to the failure return value
    je decode_error # go to error handler if there is an error

    salq $4, %r14 # shift output left 4 bits to make space for new decoded bytes
    orq %rax, %r14 # add decoded nibble to end of output

    incq %r12 # increment loop counter

    cmpq $8, %r12 # compare the loop counter to the limit
    jne get_nibbles # jump to start of loop if it is not out of range

    movq %r14, %rax # move output to rax
    jmp exit # jump to exit sequence

decode_error:

    movq $1, %rax # change rax to 1
    salq $63, %rax # set the uppermost bit of rax
    orq %r12, %rax # add number of successful conversions to rax

exit:

    # Restore saved registers
    popq %r14
    popq %r13
    popq %r12

    leave # tear down stack frame
    ret
    .size fromGCR, .-fromGCR

