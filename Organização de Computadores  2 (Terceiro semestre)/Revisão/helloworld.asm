.data
	#area para dados na memoria principal
	msg: .asciiz "Ola, mundo!" #mensagem que sera exibida ao usuario


.text
	#area para instrucoes do programa
	
	li $v0, 4 #instrucao para impressao de string
	la $a0, msg #indicar o endereco em que esta a mensagem
	syscall #faca! imprima