	.file	"macro.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	cmpl	$1, 8(%ebp)
	jle	.L2
	movl	$2, %eax
	jmp	.L3
.L2:
	movl	$1, %eax
.L3:
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	addl	$10, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
