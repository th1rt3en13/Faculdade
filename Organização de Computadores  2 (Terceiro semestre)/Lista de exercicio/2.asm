# Programa MIPS para calcular a contribuição mensal do INSS
# com base no salário bruto do empregado.

.data
salario: .asciiz "Digite o seu salario bruto: "
desconto: .asciiz "Valor a ser descontado: "
salario_liquido: .asciiz "Salario apos desconto: "
newline: .asciiz "\n"
limite1: .float 1658.38
limite2: .float 2765.66
limite3: .float 5531.31
percentual1: .float 0.08
percentual2: .float 0.09
percentual3: .float 0.11

.text
main:
    # Solicita o salário bruto do usuário
    li $v0, 4                  # Código do syscall para print_string
    la $a0, salario     # Carrega o endereço da string prompt_salario
    syscall                    # Imprime a string

    li $v0, 5                  # Código do syscall para read_int
    syscall                    # Lê um inteiro do usuário
    move $t0, $v0              # Armazena o salário bruto em $t0

    # Converte salário para ponto flutuante
    mtc1 $t0, $f0              # Move salário para $f0
    cvt.s.w $f0, $f0           # Converte salário para ponto flutuante

    # Carrega os limites e percentuais
    la $a0, limite1
    lwc1 $f2, 0($a0)           # Carrega 1658.38 para $f2
    la $a0, limite2
    lwc1 $f4, 0($a0)           # Carrega 2765.66 para $f4
    la $a0, limite3
    lwc1 $f6, 0($a0)           # Carrega 5531.31 para $f6
    la $a0, percentual1
    lwc1 $f8, 0($a0)           # Carrega 0.08 para $f8
    la $a0, percentual2
    lwc1 $f10, 0($a0)          # Carrega 0.09 para $f10
    la $a0, percentual3
    lwc1 $f12, 0($a0)          # Carrega 0.11 para $f12

    # Determina o percentual de desconto com base no salário bruto
    c.le.s $f0, $f2            # Se $f0 <= $f2 (salario <= 1658.38)
    bc1t desconto_8_percent    # Se verdadeiro, pula para desconto_8_percent

    c.le.s $f0, $f4            # Se $f0 <= $f4 (salario <= 2765.66)
    bc1t desconto_9_percent    # Se verdadeiro, pula para desconto_9_percent

    c.le.s $f0, $f6            # Se $f0 <= $f6 (salario <= 5531.31)
    bc1t desconto_11_percent   # Se verdadeiro, pula para desconto_11_percent

desconto_8_percent:
    mul.s $f14, $f0, $f8       # desconto = salario * 0.08
    j calcula_salario_liquido

desconto_9_percent:
    mul.s $f14, $f0, $f10      # desconto = salario * 0.09
    j calcula_salario_liquido

desconto_11_percent:
    mul.s $f14, $f0, $f12      # desconto = salario * 0.11
    j calcula_salario_liquido

calcula_salario_liquido:
    sub.s $f16, $f0, $f14      # salario_liquido = salario - desconto

    # Prepara para imprimir o valor a ser descontado
    li $v0, 4                  # Código do syscall para print_string
    la $a0, desconto  # Carrega o endereço da string mensagem_desconto
    syscall                    # Imprime a string

    mov.s $f12, $f14           # Move o valor do desconto para $f12
    li $v0, 2                  # Código do syscall para print_float
    syscall                    # Imprime o valor de ponto flutuante

    # Imprime uma nova linha
    li $v0, 4
    la $a0, newline
    syscall

    # Prepara para imprimir o salário líquido
    li $v0, 4                  # Código do syscall para print_string
    la $a0, salario_liquido # Carrega o endereço da string mensagem_salario_liquido
    syscall                    # Imprime a string

    mov.s $f12, $f16           # Move o salário líquido para $f12
    li $v0, 2                  # Código do syscall para print_float
    syscall                    # Imprime o valor de ponto flutuante

    # Imprime uma nova linha
    li $v0, 4
    la $a0, newline
    syscall

    # Finaliza o programa
    li $v0, 10                 # Código do syscall para exit
    syscall                    # Encerra o programa
