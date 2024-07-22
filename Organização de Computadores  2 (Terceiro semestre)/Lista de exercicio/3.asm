# Programa MIPS para orientar o cliente sobre a direção a tomar no corredor
# com base no número do quarto informado.

.data
quarto: .asciiz "Digite o numero do quarto desejado: "
direita: .asciiz "Tome o caminho a direita.\n"
esquerda: .asciiz "Tome o caminho a esquerda.\n"

.text
main:
    # Solicita o número do quarto ao usuário
    li $v0, 4                  # Código do syscall para print_string
    la $a0, quarto      # Carrega o endereço da string quarto
    syscall                    # Imprime a string

    li $v0, 5                  # Código do syscall para read_int
    syscall                    # Lê um inteiro do usuário
    move $t0, $v0              # Armazena o número do quarto em $t0

    # Verifica se o número do quarto é par ou ímpar
    andi $t1, $t0, 1           # Faz uma operação AND com 1 para verificar o bit menos significativo
    beq $t1, $zero, par        # Se o resultado for 0, o número é par
    j impar                    # Caso contrário, o número é ímpar

par:
    # Imprime a mensagem para a direita
    li $v0, 4                  # Código do syscall para print_string
    la $a0, direita            # Carrega o endereço da string direita
    syscall                    # Imprime a string
    j fim                      # Termina o programa

impar:
    # Imprime a mensagem para a esquerda
    li $v0, 4                  # Código do syscall para print_string
    la $a0, esquerda           # Carrega o endereço da string esquerda
    syscall                    # Imprime a string

fim:
    # Finaliza o programa
    li $v0, 10                 # Código do syscall para exit
    syscall                    # Encerra o programa
