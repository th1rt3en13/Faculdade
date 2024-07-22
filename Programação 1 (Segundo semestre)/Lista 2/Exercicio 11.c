#include <stdio.h>
main(){
    float peso, alt, imc;
    printf("digite seu peso: ");
    scanf ("%f", &peso);
    printf ("digite sua altura: ");
    scanf ("%f", &alt);
    imc = peso/ (alt*alt);
    if (imc<18.5){
        printf ("abaixo do peso");
    }
    else if (imc>=18.5 && imc<=24.9){
        printf("peso normal");
    }
    else if (imc>=25 && imc<=29.9){
        printf("sobre peso");
    }
    else if (imc>=30 && imc<=34.9){
        printf("obesidade grau i");
    }
    else if (imc>=35 && imc<=39.9){
        printf ("obesidade grau ii");
    }
    else{
        printf ("obesidade morbida");
    }
}
