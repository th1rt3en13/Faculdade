.data
	msg: .asciiz "digite um float: "
	msg2: .asciiz "o numero digitado foi: "
	zero: .float 0.0

.text 
	li $v0, 4
	la $a0, msg
	syscall
	
	li $v0, 6
	syscall
	
	lwc1 $f1, zero
	add.s $f12, $f1, $f0
	
	li $v0, 4
	la $a0, msg2
	syscall
	
	li $v0, 2
	syscall
	
	
	
	
