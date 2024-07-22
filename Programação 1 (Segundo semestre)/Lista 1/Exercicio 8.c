//8 – Faça um programa utilizando sua criatividade que
//tenha um diálogo com o usuário.
#include<stdio.h>
main(){
    char nome[20];
    int nasc, ano, idade;
    
    printf("Nome: ");
    scanf("%s", &nome);
    printf("Nascimento: ");
    scanf("%d", &nasc);
    idade= 2023-nasc;
    printf("Olá %s, sua idade é %d, seja bem vindo!", nome, idade);
    
}