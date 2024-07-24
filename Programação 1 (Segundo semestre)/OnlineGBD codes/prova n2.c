#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    struct empresa{
        int tip;
        char tipo[15], local[15], mes[15], cod[15];
        float dia, valor;
    };
    
    int i,j, loc,aleatorio, nt, mNt=0;
    float tot_15,tot_estadual, perc_15,totvalor,mediavalor_t, mediavalor_f, mediavalor, totvalor_f, totvalor_t, totf, tott;
    float totdia_ag, totdia_st, totdia_out, mediaagosto, mediasetembro, mediaoutubro;
    
    struct empresa offshore[105], aux;
    aleatorio=(rand()%400)+1100; 
    printf ("numero aleatorio: %d\n", aleatorio);
    for (i=0; i<105; i++){
        loc= (rand()%2);
        offshore[i].tip= (rand()%2);
        offshore[i].dia = (rand()%31)+1;
        nt= aleatorio+i;
        //mes
        if (i<34){
            sprintf (offshore[i].mes, "Agosto  ");
            totdia_ag+=offshore[i].dia;
        }
        else if (i>34 && i<70){
            sprintf (offshore[i].mes, "Setembro");
            totdia_st+=offshore[i].dia;
        }
        else{
            sprintf (offshore[i].mes, "Outubro ");
            totdia_out+=offshore[i].dia;
        }
        //local
        if (loc==0){
            sprintf (offshore[i].local,"Estadual     ");
            tot_estadual++;
            //estaduais maior que 15 dias
            if (offshore[i].dia>15){
                tot_15++;
            }
        }
        else{
            sprintf (offshore[i].local,"Interestadual");
        }
        //tipo de servico
        if (offshore[i].tip==0){
            sprintf (offshore[i].tipo,"Fretamento");
            offshore[i].valor=offshore[i].dia*300+500;
            totvalor_f+=offshore[i].valor;
            totvalor+=offshore[i].valor;
            totf++;
        }
        else{
            sprintf (offshore[i].tipo,"Transporte");
            offshore[i].valor=offshore[i].dia*450+750;
            totvalor_t+=offshore[i].valor;
            totvalor+=offshore[i].valor;
            tott++;
        }
        //codigo
        if (loc==0 && offshore[i].tip==0){
          sprintf (offshore[i].cod, "E%dF", nt);  
        }
        else if (loc==1 && offshore[i].tip==1){
          sprintf (offshore[i].cod, "I%dT", nt);  
        }
        else if (loc==0 && offshore[i].tip==1){
          sprintf (offshore[i].cod, "E%dT", nt);  
        }
        else if (loc==1 && offshore[i].tip==0){
          sprintf (offshore[i].cod, "I%dF", nt);  
        }
        
        //menor nt
        if (offshore[i].valor< offshore[mNt].valor) mNt=i;
        
        printf ("%s\t%s\t%s\t%s\t%2.0f\t%9.2f\n", offshore[i].cod,offshore[i].mes,offshore[i].tipo,offshore[i].local,offshore[i].dia,offshore[i].valor);
        
    }
    printf("\n");
    perc_15= (tot_15/tot_estadual)*100;
    printf ("Total de estadual e com mais de 15 dias: %5.1f%%\n", perc_15);
    mediavalor_f = (totvalor_f/totf);
    printf ("Media de valor Fretamento: %5.1f\n", mediavalor_f);
    mediavalor_t = (totvalor_t/tott);
    printf ("Media de valor Transporte: %5.1f\n", mediavalor_t);
    mediavalor = totvalor/i;
    printf ("Media de valor geral: %5.1f\n", mediavalor);
    printf("\n");
    printf("A NT de menor valor: \n");
    printf ("%s\t%s\t%s\t%s\t%2.0f\t%9.2f\n", offshore[mNt].cod,offshore[mNt].mes,offshore[mNt].tipo,offshore[mNt].local,offshore[mNt].dia,offshore[mNt].valor);
    printf("\n");
    mediaagosto = totdia_ag/34;
    printf ("Media de dias agosto: %5.1f\n", mediaagosto);
    mediasetembro = totdia_st/36;
    printf ("Media de dias setembro: %5.1f\n", mediasetembro);
    mediaoutubro = totdia_out/35;
    printf ("Media de dias outubro: %5.1f\n", mediaoutubro);
    printf("\n");
    
    printf ("Ordenando por tipo");
    printf("\n");
    for (i=0;i<104;i++){
        for (j=i+1;j<105;j++){
            if (offshore[i].tip>offshore[j].tip){
                aux=offshore[i];
                offshore[i]=offshore[j];
                offshore[j]=aux;
            }
        }
        printf ("%s\t%s\t%s\t%s\t%2.0f\t%9.2f\n", offshore[i].cod,offshore[i].mes,offshore[i].tipo,offshore[i].local,offshore[i].dia,offshore[i].valor);
    }
    printf("\n");
    printf ("Ordenando por valor");
    printf("\n");
    for (i=0;i<104;i++){
        for (j=i+1;j<105;j++){
            if (offshore[i].valor>offshore[j].valor){
                aux=offshore[i];
                offshore[i]=offshore[j];
                offshore[j]=aux;
            }
        }
        printf ("%s\t%s\t%s\t%s\t%2.0f\t%9.2f\n", offshore[i].cod,offshore[i].mes,offshore[i].tipo,offshore[i].local,offshore[i].dia,offshore[i].valor);
    }
    
    
    
    return 0;
}
