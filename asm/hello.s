# hello.s
    .data
    a:  .quad   0x3

    .text
    .globl      _main
_main:
    movq        a(%rip), %rax
    retq
