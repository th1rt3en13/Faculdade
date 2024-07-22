.data
massa:      .float 0.0
alt:        .float 0.0
imc:        .float 0.0
msg_massa:  .asciiz "Digite sua massa (em kg): "
msg_alt:    .asciiz "Digite sua altura (em cm): "
msg_mag_grave:   .asciiz "Magreza grave\n"
msg_mag_moderada:.asciiz "Magreza moderada\n"
msg_mag_leve:    .asciiz "Magreza leve\n"
msg_saudavel:    .asciiz "Saudável\n"
msg_sobrepeso:   .asciiz "Sobrepeso\n"
msg_ob_grau_I:   .asciiz "Obesidade grau I\n"
msg_ob_grau_II:  .asciiz "Obesidade grau II (severa)\n"
msg_ob_grau_III: .asciiz "Obesidade grau III (mórbida)\n"

.text
.globl main

main:
    # Solicitar massa
    li $v0, 4
    la $a0, msg_massa
    syscall

    li $v0, 6
    syscall
    s.s $f0, massa

    # Solicitar altura
    li $v0, 4
    la $a0, msg_alt
    syscall

    li $v0, 6
    syscall
    s.s $f0, alt

    # Converter altura de cm para metros
    l.s $f2, alt
    li $t0, 0x42C80000  # 100.0
    mtc1 $t0, $f3
    div.s $f2, $f2, $f3
    s.s $f2, alt

    # Calcular IMC: imc = massa / (alt * alt)
    l.s $f1, massa
    l.s $f2, alt
    mul.s $f3, $f2, $f2  # f3 = alt * alt
    div.s $f4, $f1, $f3  # f4 = massa / (alt * alt)
    s.s $f4, imc

    # Comparar IMC e imprimir categoria correspondente
    l.s $f0, imc

    # Usar labels para os valores de comparação
    li $t0, 0x41800000  # 16.0
    mtc1 $t0, $f1
    c.lt.s $f0, $f1
    bc1t magreza_grave

    li $t0, 0x41880000  # 17.0
    mtc1 $t0, $f1
    c.lt.s $f0, $f1
    bc1t magreza_moderada

    li $t0, 0x41940000  # 18.5
    mtc1 $t0, $f1
    c.lt.s $f0, $f1
    bc1t magreza_leve

    li $t0, 0x41C80000  # 25.0
    mtc1 $t0, $f1
    c.lt.s $f0, $f1
    bc1t saudavel

    li $t0, 0x41F00000  # 30.0
    mtc1 $t0, $f1
    c.lt.s $f0, $f1
    bc1t sobrepeso

    li $t0, 0x420C0000  # 35.0
    mtc1 $t0, $f1
    c.lt.s $f0, $f1
    bc1t obesidade_I

    li $t0, 0x42200000  # 40.0
    mtc1 $t0, $f1
    c.lt.s $f0, $f1
    bc1t obesidade_II

    # Obesidade grau III (mórbida)
    la $a0, msg_ob_grau_III
    j print_message

magreza_grave:
    la $a0, msg_mag_grave
    j print_message

magreza_moderada:
    la $a0, msg_mag_moderada
    j print_message

magreza_leve:
    la $a0, msg_mag_leve
    j print_message

saudavel:
    la $a0, msg_saudavel
    j print_message

sobrepeso:
    la $a0, msg_sobrepeso
    j print_message

obesidade_I:
    la $a0, msg_ob_grau_I
    j print_message

obesidade_II:
    la $a0, msg_ob_grau_II
    j print_message

print_message:
    li $v0, 4
    syscall

    # Encerrar o programa
    li $v0, 10
    syscall



