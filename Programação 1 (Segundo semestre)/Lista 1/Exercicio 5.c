#include <stdio.h>
int main(){
    char nome[20];
    int nasc, ano, idade;
    printf ("EXERCICIO 5 \n");
    printf("qual o seu nome? ");
    scanf("%s", &nome);
    printf("em que ano você nasceu? " );
    scanf ("%d", &nasc);
    printf ("escolha o ano que você gostaria de saber a sua idade: ");
    scanf ("%d", &ano);
    idade = ano - nasc;
    printf("Em %d, você terá %d anos", ano, idade);
    
}
