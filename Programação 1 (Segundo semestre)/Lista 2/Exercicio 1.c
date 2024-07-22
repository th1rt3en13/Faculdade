//Fazer um programa que receba três valores e verifique se estes podem ser os lados de um triângulo.
#include<stdio.h>
main()
{
    int a,b,c;
    printf ("Digite o valor 1: ");
    scanf("%d", &a);
    printf ("Digite o valor 2: ");
    scanf("%d", &b);
    printf ("Digite o valor 3: ");
    scanf("%d", &c);
    
    if (a + b > c && a + c > b && b + c > a) {
        printf("Os valores formam um triângulo.\n");
    } else {
        printf("Os valores não formam um triângulo.\n");
    }
}