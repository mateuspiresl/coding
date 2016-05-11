	.file	"dummy.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushl	%ebp
.LCFI0:
	movl	%esp, %ebp
.LCFI1:
	subl	$16, %esp
	movl	$100, _ZN5Dummy2x_E
	movl	$2, -12(%ebp)
	movl	$3, -8(%ebp)
	movl	$4, -4(%ebp)
	movl	-12(%ebp), %edx
	movl	-8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	addl	%edx, %eax
	leave
.LCFI2:
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
