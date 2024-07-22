//Fazer Um programa que receba três valores A, B , C e OP, quando OP=1 apresente em ordem
//crescente caso contrário os números devem ser apresentados em ordem decrescente.
#include<stdio.h>
main(){
    int a,b,c, op;
    printf("digite o valor a: ");
    scanf ("%d", &a);
    printf ("digite o valor b: ");
    scanf ("%d", &b);
    printf("digite o valor c: ");
    scanf ("%d", &c);
     printf("digite o valor OP: ");
    scanf ("%d", &op);
    
    if (op==1){
        if (a>b && b>c){
            printf ("%d,%d,%d",c, b, a);
        }
        if (c>b && b>a){
            printf ("%d, %d, %d", a,b,c);
        }
        if (b>a && a>c){
             printf ("%d, %d, %d", c, a ,b);
        }
        if (a>c && c>b){
            printf ("%d,%d,%d", b,c,a);
        }
        if (b>c && c>a){
            printf ("%d,%d,%d", a,c,b);
        }
         if (c>a && a>b){
            printf ("%d, %d, %d", b,a, c );
        }
    }
    else {
        if (a>b && b>c){
            printf ("%d,%d,%d",a,b,c);
        }
        if (c>b && b>a){
            printf ("%d, %d, %d", c,b,a);
        }
        if (b>a && a>c){
             printf ("%d, %d, %d", b,a,c);
        }
        if (a>c && c>b){
            printf ("%d,%d,%d", a,c,b);
        }
        if (b>c && c>a){
            printf ("%d,%d,%d", b,c,a);
        }
         if (c>a && a>b){
            printf ("%d, %d, %d", c,a,b );
        }
        
    }
}
