#include <stdio.h>
main(){
    int a;
    printf ("numero: ");
    scanf ("%d", &a);
    if (a%3==0){
        printf ("multiplo de 3");
    }
    else {
        printf ("nao eh multiplo de 3");
    }
}
