	.file	"assembly1.c"
	.globl	x								# variável visível para outras unidade de tradução do C
	.data									# sessão data
	.align 4
	.type	x, @object
	.size	x, 4							# espaço reservado em bytes para o x
x:											# endereço de memória de x
	.long	10								# escreve o valor do tipo long em x
	.comm	y,4,4							# sessão bss; ?globais não inicializadas? ?nome,size,size?
	.text									# sessão text (código executável)
	.globl	main
	.type	main, @function
main:										# endereço de memória da função main
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$20, y(%rip)
	movl	x(%rip), %edx
	movl	y(%rip), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	$0, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
