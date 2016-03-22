	.file	"atv2.c"
	.text
	.globl	fillBottle
	.type	fillBottle, @function
fillBottle:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	%rdi, -16(%rbp)
	movl	%esi, -4(%rbp)
	movl	-12(%rbp), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movq	-16(%rbp), %rax
	popq	%rbp
	ret
	.size	fillBottle, .-fillBottle
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
	movb	$67, -16(%rbp)
	movl	$0, -12(%rbp)
	movq	-16(%rbp), %rax
	movl	$12, %esi
	movq	%rax, %rdi
	call	fillBottle
	movq	%rax, -16(%rbp)
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
