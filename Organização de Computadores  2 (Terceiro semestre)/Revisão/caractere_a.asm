.data
	caractere: .byte 'a' #catactere letra a
.text
	li $v0, 4 #imprimir char ou string
	la $a0, caractere
	syscall