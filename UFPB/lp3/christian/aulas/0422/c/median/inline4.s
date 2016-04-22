	.file	"inline4.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	xorl	%ebx, %ebx
	subl	$16, %esp
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
	subl	$8, %esp
	pushl	$5
	pushl	$y
	call	Median
	fnstcw	-10(%ebp)
	movzwl	-10(%ebp), %eax
	addl	$16, %esp
	movb	$12, %ah
	movw	%ax, -12(%ebp)
	fldcw	-12(%ebp)
	fistpl	-16(%ebp)
	fldcw	-10(%ebp)
	movl	-16(%ebp), %eax
	imull	y, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	popl	%ebx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	leal	y+4(,%eax,4), %eax
	jmp	.L3
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE1:
	.section	.text.startup
.LHOTE1:
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
