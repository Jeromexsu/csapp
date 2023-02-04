	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_sum                            ## -- Begin function sum
	.p2align	4, 0x90
_sum:                                   ## @sum
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	testl	%esi, %esi
	jle	LBB0_1
## %bb.2:
	movl	%esi, %ecx
	xorl	%edx, %edx
	xorl	%eax, %eax
	.p2align	4, 0x90
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	addl	(%rdi,%rdx,4), %eax
	addq	$1, %rdx
	cmpq	%rdx, %rcx
	jne	LBB0_3
## %bb.4:
	popq	%rbp
	retq
LBB0_1:
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
