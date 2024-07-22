

#include <stdio.h>
int main(){
    char nome[20];
    int nasc, idade;
    printf ("EXERCICIO 3 \n");
    printf("qual o seu nome? ");
    scanf("%s", &nome);
    printf("em que ano você nasceu?" );
    scanf ("%d", &nasc);
    idade = 2020 - nasc;
    printf("em 2020, você terá %d anos", idade);
}
