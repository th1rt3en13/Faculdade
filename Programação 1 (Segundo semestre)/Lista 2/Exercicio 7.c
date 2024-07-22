#include<stdio.h>
main(){
    int a,b, soma;
    
    printf("digite o primeiro numero: ");
    scanf ("%d", &a);
    printf ("digite o segundo numero: ");
    scanf ("%d", &b);
    soma = a+b;
    
    if (soma> 20){
        soma = soma + 8;
        printf ("%d", soma);
    }
    else{
        soma = soma - 5;
        printf("%d", soma);
    }
}
