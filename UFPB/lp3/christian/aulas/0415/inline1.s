	.file	"inline1.c"
	.text
	.p2align 4,,15
	.globl	F1
	.type	F1, @function
F1:
	movl	4(%esp), %eax
	addl	$1, %eax
	ret
	.size	F1, .-F1
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
	xorl	%eax, %eax
	cmpl	$1, 4(%esp)
	setg	%al
	addl	$2, %eax
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
