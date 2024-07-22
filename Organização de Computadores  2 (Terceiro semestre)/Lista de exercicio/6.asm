.data
    prompt_vendas: .asciiz "Digite o valor das vendas: "
    prompt_continuar: .asciiz "Digite 0 para sair, ou outro numero para continuar: "
    resultado: .asciiz "Salario fixo + comissao = R$ "
    valor_comissao: .float 0.0
    valor_comissao_adicional: .float 0.0
    salario_fixo: .float 1200.0
    comissao_10: .float 0.10
    comissao_20: .float 0.20
    valor_1500: .float 1500.0

.text
.globl main

main:
    # Inicializa as variáveis
    li $t0, 1          # i = 1

loop:
    beqz $t0, end      # Se i == 0, sai do loop

    # Solicita o valor das vendas
    li $v0, 4
    la $a0, prompt_vendas
    syscall

    li $v0, 6          # Leitura de float
    syscall
    mov.s $f4, $f0     # vendas = $f0

    # Carrega constantes
    la $t1, valor_1500
    lwc1 $f5, 0($t1)
    la $t2, comissao_10
    lwc1 $f7, 0($t2)
    la $t3, salario_fixo
    lwc1 $f3, 0($t3)
    la $t4, comissao_20
    lwc1 $f9, 0($t4)

    # Se vendas <= 1500
    c.le.s $f4, $f5
    bc1t menor_igual_1500

    # vendas > 1500
    # comissao = 1500 * 0.10
    mul.s $f1, $f5, $f7

    # comissao_adicional = (vendas - 1500) * 0.20
    sub.s $f8, $f4, $f5
    mul.s $f2, $f8, $f9

    # tot = salario_fixo + comissao + comissao_adicional
    add.s $f10, $f3, $f1
    add.s $f11, $f10, $f2
    b imprimir

menor_igual_1500:
    # comissao = vendas * 0.10
    mul.s $f1, $f4, $f7

    # tot = salario_fixo + comissao
    add.s $f11, $f3, $f1

imprimir:
    # Exibe o resultado
    li $v0, 4
    la $a0, resultado
    syscall

    li $v0, 2
    mov.s $f12, $f11
    syscall

    # Solicita se deseja continuar
    li $v0, 4
    la $a0, prompt_continuar
    syscall

    li $v0, 5          # Leitura de int
    syscall
    move $t0, $v0      # i = $v0

    j loop

end:
    li $v0, 10         # Saída do programa
    syscall



