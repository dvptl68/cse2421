# Dev Patel

# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT 
# ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS.I WROTE THIS CODE BY HAND,
# IT IS NOT MACHINE GENRATED OR TAKEN FROM MACHINE GENERATED CODE.

# Directives
.file "count.s"
.section .rodata

# Constant array to hold table of ranges
ranges:
    .byte 48  # ASCII value for 0
    .byte 57  # ASCII value for 9
    .byte 65  # ASCII value for A
    .byte 90  # ASCII value for Z
    .byte 97  # ASCII value for a
    .byte 122 # ASCII value for z

.data
.align 8

# Count function
.globl count
    .type count, @function
.text
count:

    pushq %rbp # save caller rbp
    movq %rsp, %rbp # set function frame pointer

    xorq %rdx, %rdx # rdx is the starting ASCII value for current range
    xorq %rcx, %rcx # rcx is the ending ASCII value for current range

    movq $ranges, %r8 # r8 is a pointer to the ranges array
    movb (%r8, %rsi, 2), %dl # set dl (rdx) to the starting ASCII value
    movb 1(%r8, %rsi, 2), %cl # set cl (rcx) to the ending ASCII value

    xorq %rax, %rax # rax is the return value and holds word count
    xorq %rsi, %rsi # second parameter is not needed anymore, so rsi is now the the current character in the loop
    xorq %r8, %r8 # range array is not needed anymore - so r8 now determines if a character is part of a bigger word - it is always 0 or 1

count_words:

    movb (%rdi), %sil # get current character from pointer and put in sil

    testb %sil, %sil # check if the current character is null
    je done # jump to end of function if current character is null

    cmpb %sil, %cl # compare end ASCII value to current character
    jb not_in_range # jump to not in range commands if current character is not below end value

    cmpb %sil, %dl # compare start ASCII value to current character
    ja not_in_range # jump to not in range commands if current character is not above start value

    testb %r8b, %r8b # check if current character is part of a bigger word
    jne continue_loop # continue through loop if current character is part of a bigger word

    incb %r8b # set r8b to 1 to indicate that a word was found
    incq %rax # increment total word count since a new word is found

    jmp continue_loop # continue through loop to avoid not in range commands

not_in_range:

    xorb %r8b, %r8b # clear r8b to indicate that no word is found

continue_loop:

    incq %rdi # increment pointer to next char
    jmp count_words # go back to top of loop to check next character

done:

    leave # tear down stack frame
    ret

.size count, .-count

