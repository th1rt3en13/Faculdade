//Fazer um programa em C que crie, preencha e apresente um vetor de 15 posições de reais entre 0 e 10,0.
//Apresente a frente de cada valor a mensagem aprovado para valores acima de 5,9 e reprovado para os demais valores.
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i;
    float vetor1[15];
    char classificao[15];
    srand(time(NULL));
    for (i=0;i<=14;i++){
        vetor1[i]= (rand()%10);
        //printf (" %1.1f \n", vetor1[i]);
        if (vetor1[i]>5.9){
            sprintf (classificao, "Aprovado"); }
        else {
            sprintf (classificao, "Reprovado");
        }
        printf ("%s\t %1.1f \n", classificao, vetor1[i]);
    }

    return 0;
}

