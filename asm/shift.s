	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_shift                          ## -- Begin function shift
	.p2align	4, 0x90
_shift:                                 ## @shift
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	shll	$2, %eax
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %ecx
	movl	-4(%rbp), %eax
                                        ## kill: def $cl killed $ecx
	sarl	%cl, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
