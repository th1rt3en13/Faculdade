#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    struct pokedex{
        char tipop[20],genero[10];
        int forca, codigo;
    }; //importante colocar ; depois da } do struct (para fechar)
    int i,j, tipo, sexo, result;
    struct pokedex pokemon[10], aux;
    printf ("\t\t\tPOKEDEX\n");
    printf("Codigo:\t Tipo:\t\t Genero:\t\tForça:\n");
    printf("\n");
    for (i=1; i<10; i++){
        //printf ("%d\n", i);
        tipo = (rand()%3)+1;
        sexo = (rand()%3);
        pokemon[i].codigo= 1000+i;
        pokemon[i].forca = (rand()%100)+1;
        if (tipo==1){
            sprintf(pokemon[i].tipop, "Venenoso ");
        }
        else if (tipo==2){
            sprintf(pokemon[i].tipop, "Fogo     ");
        }
        else{
            sprintf(pokemon[i].tipop, "Agua     ");
        }
        if (sexo==1){
            sprintf(pokemon[i].genero, "Feminino ");
        }
        else{
            sprintf(pokemon[i].genero, "Masculino");
        }
        printf ("%d\t %s\t %s\t\t %d\n", pokemon[i].codigo, pokemon[i].tipop, pokemon[i].genero, pokemon[i].forca);
    }
    printf ("\n");
    printf("======================================================\n");
    printf ("\n");
    printf ("ORDEM ALFABETICA DO TIPO: \n");
    printf ("\n");
    printf ("Codigo:\tTipo:\n");
    printf ("\n");
    for (i=1; i<9; i++){
        for (j=i+1; j<10; j++){
            result = strcmp(pokemon[i].tipop, pokemon[j].tipop);
            if (result>0){
                aux=pokemon[i];
                pokemon[i]=pokemon[j];
                pokemon[j]=aux;    
            }
            }
            printf ("%d\t%s\n",pokemon[i].codigo, pokemon[i].tipop);
        }
        //nao esquecer de colocar o segundo print se nao n imprime tudo
        printf ("%d\t%s\n",pokemon[i].codigo, pokemon[i].tipop);
    }
    



