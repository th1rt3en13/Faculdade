.data
msg_altura_lado:    .asciiz "Digite a altura do lado "
msg_largura_lado:   .asciiz "Digite a largura do lado "
msg_ladrilho_altura:.asciiz "Informe a altura do ladrilho: "
msg_ladrilho_largura:.asciiz "Informe a largura do ladrilho: "
msg_resultado:      .asciiz "A quantidade de ladrilhos necessaria eh de: "
linha:              .asciiz "\n"

area_tot_pis: .float 0.0
alt_pis:      .float 0.0
larg_pis:     .float 0.0
lado_1:       .float 0.0
lado_2:       .float 0.0
area_lad:     .float 0.0
qtd_lad:      .float 0.0
i:            .word 0

.text
.globl main

main:
    # Inicializa i com 0
    li $t0, 0
    sw $t0, i

    # Inicializa area_tot_pis com 0.0
    li $t0, 0
    mtc1 $t0, $f0
    s.s $f0, area_tot_pis

loop:
    lw $t0, i
    li $t1, 5
    bge $t0, $t1, ladrilho_prompt

    # Prompt para altura do lado
    li $v0, 4
    la $a0, msg_altura_lado
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 4
    la $a0, linha
    syscall

    li $v0, 6
    syscall
    s.s $f0, alt_pis

    # Prompt para largura do lado
    li $v0, 4
    la $a0, msg_largura_lado
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 4
    la $a0, linha
    syscall

    li $v0, 6
    syscall
    s.s $f0, larg_pis

    # Calcular area_tot_pis += alt_pis * larg_pis
    l.s $f1, alt_pis
    l.s $f2, larg_pis
    mul.s $f3, $f1, $f2

    l.s $f4, area_tot_pis
    add.s $f4, $f4, $f3
    s.s $f4, area_tot_pis

    # Incrementa i
    lw $t0, i
    addi $t0, $t0, 1
    sw $t0, i
    j loop

ladrilho_prompt:
    # Prompt para altura do ladrilho
    li $v0, 4
    la $a0, msg_ladrilho_altura
    syscall

    li $v0, 6
    syscall
    s.s $f0, lado_1

    # Prompt para largura do ladrilho
    li $v0, 4
    la $a0, msg_ladrilho_largura
    syscall

    li $v0, 6
    syscall
    s.s $f0, lado_2

    # Calcular area_lad = lado_1 * lado_2
    l.s $f1, lado_1
    l.s $f2, lado_2
    mul.s $f3, $f1, $f2
    s.s $f3, area_lad

    # Calcular qtd_lad = area_tot_pis / area_lad
    l.s $f4, area_tot_pis
    l.s $f5, area_lad
    div.s $f6, $f4, $f5
    s.s $f6, qtd_lad

    # Mostrar o resultado
    li $v0, 4
    la $a0, msg_resultado
    syscall

    li $v0, 2
    l.s $f12, qtd_lad
    syscall

    # Adicionar uma nova linha no final
    li $v0, 4
    la $a0, linha
    syscall

    # Termina o programa
    li $v0, 10
    syscall

