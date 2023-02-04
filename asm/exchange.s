    .text
    .globl      _main
_main:
	movq		$3,%rdi
	movq		$5,%rsi
    movq        %rdi,%rax
	movq		%rsi,%rdi
	movq		%rax,%rsi
    retq
