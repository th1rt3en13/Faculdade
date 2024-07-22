#include<stdio.h>
main(){
    int a,b,c;
    printf("digite o valor a: ");
    scanf ("%d", &a);
    printf ("digite o valor b: ");
    scanf ("%d", &b);
    printf("digite o valor c: ");
    scanf ("%d", &c);
    
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

