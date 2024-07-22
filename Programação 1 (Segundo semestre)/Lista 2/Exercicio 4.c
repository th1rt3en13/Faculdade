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
    } if (a==b && b==c){
        printf ("Triângulo Equilátero");
      }
      else if (a!=b && b!=c){
          printf ("Triângulo Escaleno");
      }
      else {
          printf("Triângulo Isósceles");
      }
    
}