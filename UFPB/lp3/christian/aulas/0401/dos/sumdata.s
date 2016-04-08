	.file	"sumdata.c"
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 20
x:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.text
	.globl	Sum
	.type	Sum, @function
Sum:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
	movl	$0, -8(%ebp)
	jmp	.L2
.L5:
	cmpl	$0, 8(%ebp)
	je	.L3
	movl	-8(%ebp), %eax
	movl	x(,%eax,4), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L4
.L3:
	movl	-8(%ebp), %eax
	movl	x(,%eax,4), %eax
	addl	%eax, -4(%ebp)
.L4:
	addl	$1, -8(%ebp)
.L2:
	cmpl	$4, -8(%ebp)
	jle	.L5
	movl	-4(%ebp), %eax
	leave
	ret
	.size	Sum, .-Sum
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
