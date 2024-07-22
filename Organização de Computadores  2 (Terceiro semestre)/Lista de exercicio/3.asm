# Programa MIPS para orientar o cliente sobre a dire��o a tomar no corredor
# com base no n�mero do quarto informado.

.data
quarto: .asciiz "Digite o numero do quarto desejado: "
direita: .asciiz "Tome o caminho a direita.\n"
esquerda: .asciiz "Tome o caminho a esquerda.\n"

.text
main:
    # Solicita o n�mero do quarto ao usu�rio
    li $v0, 4                  # C�digo do syscall para print_string
    la $a0, quarto      # Carrega o endere�o da string quarto
    syscall                    # Imprime a string

    li $v0, 5                  # C�digo do syscall para read_int
    syscall                    # L� um inteiro do usu�rio
    move $t0, $v0              # Armazena o n�mero do quarto em $t0

    # Verifica se o n�mero do quarto � par ou �mpar
    andi $t1, $t0, 1           # Faz uma opera��o AND com 1 para verificar o bit menos significativo
    beq $t1, $zero, par        # Se o resultado for 0, o n�mero � par
    j impar                    # Caso contr�rio, o n�mero � �mpar

par:
    # Imprime a mensagem para a direita
    li $v0, 4                  # C�digo do syscall para print_string
    la $a0, direita            # Carrega o endere�o da string direita
    syscall                    # Imprime a string
    j fim                      # Termina o programa

impar:
    # Imprime a mensagem para a esquerda
    li $v0, 4                  # C�digo do syscall para print_string
    la $a0, esquerda           # Carrega o endere�o da string esquerda
    syscall                    # Imprime a string

fim:
    # Finaliza o programa
    li $v0, 10                 # C�digo do syscall para exit
    syscall                    # Encerra o programa
