//Fazer um programa que peça seu nome e ano de
//nascimento, calcule e apresente a sua idade no ano de 2021
#include<stdio.h>
main(){
    int nasc, idade;
    char nome[20];
    printf("Em que ano você nasceu: ");
    scanf("%d", &nasc);
    idade= 2021-nasc;
    printf("Você tem %d anos", idade);
}