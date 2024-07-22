.data
prompt:          .asciiz "Digite o valor do salario: "
output1:         .asciiz "O valor do imposto de renda devido e: R$ "
salario:         .float 0.0
imposto:         .float 0.0
valor_1903_98:   .float 1903.98
valor_2826_65:   .float 2826.65
valor_3751_05:   .float 3751.05
valor_4664_68:   .float 4664.68
taxa_0:          .float 0.0
taxa_7_5:        .float 0.075
taxa_15:         .float 0.15
taxa_22_5:       .float 0.225
taxa_27_5:       .float 0.275

.text
.globl main

main:
    
    li $v0, 4
    la $a0, prompt
    syscall

  
    li $v0, 6
    syscall
    s.s $f0, salario 

 
    l.s $f0, salario
    l.s $f1, valor_1903_98
    c.le.s $f0, $f1
    bc1t isento

    l.s $f1, valor_2826_65
    c.le.s $f0, $f1
    bc1t faixa_7_5_label

    l.s $f1, valor_3751_05
    c.le.s $f0, $f1
    bc1t faixa_15_label

    l.s $f1, valor_4664_68
    c.le.s $f0, $f1
    bc1t faixa_22_5_label

faixa_27_5_label:
    l.s $f1, taxa_27_5
    mul.s $f2, $f0, $f1
    s.s $f2, imposto
    j print_output

faixa_22_5_label:
    l.s $f1, taxa_22_5
    mul.s $f2, $f0, $f1
    s.s $f2, imposto
    j print_output

faixa_15_label:
    l.s $f1, taxa_15
    mul.s $f2, $f0, $f1
    s.s $f2, imposto
    j print_output

faixa_7_5_label:
    l.s $f1, taxa_7_5
    mul.s $f2, $f0, $f1
    s.s $f2, imposto
    j print_output

isento:
    l.s $f2, taxa_0
    s.s $f2, imposto

print_output:
    # Print imposto
    li $v0, 4
    la $a0, output1
    syscall

    l.s $f12, imposto
    li $v0, 2
    syscall

    #sair
    li $v0, 10
    syscall