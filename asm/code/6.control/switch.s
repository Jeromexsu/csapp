	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	_switch_eg                      ## -- Begin function switch_eg
	.p2align	4, 0x90
_switch_eg:                             ## @switch_eg
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	addq	$-100, %rsi
	cmpq	$6, %rsi
	ja	LBB0_6
## %bb.1:
	leaq	LJTI0_0(%rip), %rcx
	movslq	(%rcx,%rsi,4), %rsi
	addq	%rcx, %rsi
	jmpq	*%rsi
LBB0_4:
	imulq	%rdi, %rdi
	jmp	LBB0_5
LBB0_2:
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rax
	jmp	LBB0_6
LBB0_3:
	addq	$10, %rdi
LBB0_5:
	movq	%rdi, %rax
LBB0_6:
	movq	%rax, (%rdx)
	popq	%rbp
	retq
	.cfi_endproc
	.p2align	2, 0x90
	.data_region jt32
.set L0_0_set_2, LBB0_2-LJTI0_0
.set L0_0_set_6, LBB0_6-LJTI0_0
.set L0_0_set_3, LBB0_3-LJTI0_0
.set L0_0_set_4, LBB0_4-LJTI0_0
LJTI0_0:
	.long	L0_0_set_2
	.long	L0_0_set_6
	.long	L0_0_set_3
	.long	L0_0_set_6
	.long	L0_0_set_4
	.long	L0_0_set_6
	.long	L0_0_set_4
	.end_data_region
                                        ## -- End function
.subsections_via_symbols
