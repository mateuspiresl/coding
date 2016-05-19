	.file	"mainptr.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	leal	4(%esp), %ecx
.LCFI0:
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
.LCFI1:
	movl	%esp, %ebp
	pushl	%ecx
.LCFI2:
	subl	$20, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$10, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L3
	call	__stack_chk_fail
.L3:
	addl	$20, %esp
	popl	%ecx
.LCFI3:
	popl	%ebp
.LCFI4:
	leal	-4(%ecx), %esp
.LCFI5:
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
