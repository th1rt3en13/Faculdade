#include <stdio.h>
int main(){
    char nome[20];
    int ano, idade;
    printf ("EXERCICIO 4 \n");
    printf("qual o seu nome? ");
    scanf("%s", &nome);
    printf("sua idade: " );
    scanf ("%d", &idade);
    printf ("digite o ano atual: ");
    scanf ("%d", &ano);
    printf("nome: %s, idade: %d, ano atual: %d", nome, idade, ano);
    
}