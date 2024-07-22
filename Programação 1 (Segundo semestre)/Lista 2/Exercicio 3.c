//Fazer um programa que receba duas notas N1, N2 e o percentual de Frequência de um aluno e
//verifique a situação do aluno: (Aprovado – Reprovado – Prova Final)
#include<stdio.h>
main(){
    float peso, alt, imc;
    printf ("Peso: ");
    scanf ("%f", &peso);
    printf ("Altura: ");
    scanf ("%f", &alt);
    imc = peso/(alt*alt);
    
    if (imc>=18.5 && imc<25){
        printf ("Peso ideal");
    }
    else {
        printf ("Peso não ideal");
    }
}