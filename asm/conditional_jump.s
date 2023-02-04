# conditional_jump.s
    .data
    a:  .quad   0x5

    .text
    .globl      _main
jump_begin:
    movq        a(%rip),%rax
_main:
    cmp         a(%rip),%rax
    jne         jump_begin
    retq