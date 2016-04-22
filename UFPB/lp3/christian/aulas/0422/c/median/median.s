	.file	"median.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	Median
	.type	Median, @function
Median:
	pushl	%ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$40, %esp
	movl	64(%esp), %esi
	leal	0(,%esi,4), %edi
	pushl	%edi
	call	malloc
	addl	$12, %esp
	movl	%eax, %ebx
	pushl	%edi
	pushl	56(%esp)
	leal	-1(%esi), %edi
	pushl	%eax
	call	memcpy
	addl	$16, %esp
	xorl	%ecx, %ecx
	cmpl	$1, %esi
	jle	.L9
	.p2align 4,,10
	.p2align 3
.L13:
	testl	%ecx, %ecx
	movl	4(%ebx,%ecx,4), %edx
	movl	%ecx, %eax
	js	.L6
	movl	(%ebx,%ecx,4), %ebp
	cmpl	%ebp, %edx
	jl	.L7
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L21:
	movl	(%ebx,%eax,4), %ebp
	cmpl	%ebp, %edx
	jge	.L6
.L7:
	movl	%ebp, 4(%ebx,%eax,4)
	subl	$1, %eax
	cmpl	$-1, %eax
	jne	.L21
	movl	$-1, %eax
.L6:
	addl	$1, %ecx
	movl	%edx, 4(%ebx,%eax,4)
	cmpl	%edi, %ecx
	jne	.L13
.L9:
	testl	$1, %esi
	jne	.L22
	movl	%esi, %eax
	shrl	$31, %eax
	addl	%eax, %esi
	sarl	%esi
	movl	(%ebx,%esi,4), %eax
	addl	-4(%ebx,%esi,4), %eax
	movl	%eax, 8(%esp)
	fildl	8(%esp)
	fstps	12(%esp)
	flds	12(%esp)
	fmuls	.LC0
	fstps	12(%esp)
	flds	12(%esp)
.L10:
	fstps	8(%esp)
	subl	$12, %esp
	pushl	%ebx
	call	free
	flds	24(%esp)
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
.L11:
	movl	%ecx, %eax
	jmp	.L6
.L22:
	movl	%esi, %eax
	shrl	$31, %eax
	addl	%eax, %esi
	sarl	%esi
	fildl	(%ebx,%esi,4)
	fstps	12(%esp)
	flds	12(%esp)
	jmp	.L10
	.size	Median, .-Median
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC0:
	.long	1056964608
	.ident	"GCC: (Debian 5.3.1-5) 5.3.1 20160101"
	.section	.note.GNU-stack,"",@progbits
