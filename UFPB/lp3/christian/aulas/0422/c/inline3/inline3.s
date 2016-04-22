	.file	"inline3.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.section	.text.startup,"ax",@progbits
.LHOTB0:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
	pushl	%ebx
	xorl	%ebx, %ebx
.L5:
	movl	y+4(,%ebx,4), %ecx
	movl	%ebx, %eax
	.p2align 4,,10
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
	movl	%ecx, (%eax)
	cmpl	$4, %ebx
	jne	.L5
	movl	y, %eax
	popl	%ebx
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	leal	y+4(,%eax,4), %eax
	jmp	.L3
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE0:
	.section	.text.startup
.LHOTE0:
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
	.ident	"GCC: (Debian 5.3.1-5) 5.3.1 20160101"
	.section	.note.GNU-stack,"",@progbits
