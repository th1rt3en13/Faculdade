//Fazer um programa que receba duas notas N1, N2 e o percentual de Frequência de um aluno e
//verifique a situação do aluno: (Aprovado – Reprovado – Prova Final)
#include<stdio.h>
main(){
    int n1,n2; 
    float perc, media;
    printf ("Nota n1: ");
    scanf ("%d", &n1);
    printf ("Nota n2: ");
    scanf ("%d", &n2);
    printf ("Percentual de faltas: ");
    scanf ("%f", &perc);
    media= (n1+n2)/2;
    
    if (perc>25){
        printf ("Reprovado por falta");
    }
    else if (media>7) {
        printf ("Aprovado");
    }
    else if (media<7 && media>4){
        printf ("Prova final");
    }
    else{
        printf("Reprovado");
    }
}