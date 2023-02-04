# Fibonacci.s
    .text
    .globl  _main
_main:
    movq    $13,%rdi
    movq    $1,%rax
    movq    $1,%rdx
    loop:
        movq    %rax,%rcx
        addq    %rdx,%rax    
        movq    %rcx,%rdx
        decq    %rdi
        cmp     $2,%rdi
        jg      loop
    ret

