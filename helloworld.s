# helloworld.s
    .section    __TEXT,__cstring
helloworld:
    .asciz      "Hello, world! \n"

    .text
    .globl      _main
_main:
    pushq       %rbp                        # stack alignment
    leaq        helloworld(%rip), %rdi
    movb        $0,%al
    callq       _printf
    popq        %rbp                        # stack alignment

    movq        $0,%rax
    retq
