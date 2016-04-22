	.file	"inline2.c"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
	pushl	%ebx
	xorl	%ebx, %ebx
.L6:
	movl	y+4(,%ebx,4), %ecx
	movl	%ebx, %eax
	.p2align 4,,7
	.p2align 3
.L2:
	movl	y(,%eax,4), %edx
	cmpl	%edx, %ecx
	jge	.L10
	movl	%edx, y+4(,%eax,4)
	subl	$1, %eax
	cmpl	$-1, %eax
	jne	.L2
	movl	$y, %eax
.L3:
	addl	$1, %ebx
	cmpl	$4, %ebx
	movl	%ecx, (%eax)
	jne	.L6
	movl	y, %eax
	popl	%ebx
	ret
	.p2align 4,,7
	.p2align 3
.L10:
	leal	y+4(,%eax,4), %eax
	jmp	.L3
	.size	main, .-main
	.globl	y
	.data
	.align 4
	.type	y, @object
	.size	y, 20
y:
	.long	5
	.long	4
	.long	3
	.long	2
	.long	1
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
