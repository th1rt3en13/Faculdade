//Fazer um programa que peça seu nome, ano de
//nascimento, seu peso e altura. Calcule calcule e
//apresente a sua idade e IMC.
#include<stdio.h>
main(){
    char nome[20];
    int nasc, ano, idade;
    float peso, alt, imc;
    
    printf("Nome: ");
    scanf("%s", &nome);
    printf("Nascimento: ");
    scanf("%d", &nasc);
    idade= 2023-nasc;
    printf("Peso: ");
    scanf("%f", &peso);
    printf("Altura: ");
    scanf("%f", &alt);
    imc= peso/(alt*alt);
    printf("%s, sua idade é %d e seu imc é de: %f", nome, idade, imc);
    
}