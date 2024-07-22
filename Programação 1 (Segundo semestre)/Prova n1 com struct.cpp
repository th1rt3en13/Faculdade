//Prova n1 2023.2 com struct
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); 
    
    struct servicos {
        int cod;
        char os[10], unidade[10],servico[20], complexidade[20];
        float horas, valor;
        };
    
    int i,j, tipo_servico,lugar, complexo;
    float perc_cal_mac,perc_usi_mac, tot_servico_macae=0, tot_servico_macae_1=0,tot_servico_macae_2=0;
    float tot_alta100,tot_complex,perc_alta100, tot_hora,tot_hora_cal,tot_hora_usi, media_cal, media_usi;
    struct servicos offshore[150],aux;
    
    for (i=0; i<150;i++){
        offshore[i].cod=i+101;
        tipo_servico = (rand()%3)+1;
        lugar = (rand()%3)+1;
        complexo = (rand()%4)+1;
        offshore[i].horas= (rand()%152)+8;
        
        //fazendo codigo OS
        if (tipo_servico==1){
            sprintf (offshore[i].os, "%dCAL", offshore[i].cod);
            sprintf (offshore[i].servico, "Caldeiraria");
            tot_hora+=offshore[i].horas;
            tot_hora_cal+=offshore[i].horas;
        }
        else{
            sprintf (offshore[i].os, "%dUSI", offshore[i].cod);
            sprintf (offshore[i].servico, "Usinagem");
            tot_hora+=offshore[i].horas;
            tot_hora_usi+=offshore[i].horas;
        }
        
        //fazendo o lugar
        if (lugar==1){
            sprintf (offshore[i].unidade, "Macae");
        }
        else{
            sprintf (offshore[i].unidade, "Santos");
        }
        
        //nivel de complexidade
        if (complexo==1){
            sprintf (offshore[i].complexidade, "Baixa");
        }
        else if (complexo==2){
            sprintf (offshore[i].complexidade, "Media");
        }
        else{
            sprintf (offshore[i].complexidade, "Alta");
        }
        
        //calculando total de cada tipo de servico de macae
        if (lugar==1 && tipo_servico==1){
            tot_servico_macae++;
            tot_servico_macae_1++;
        }
        else if (lugar==1 && tipo_servico==2){
            tot_servico_macae++;
            tot_servico_macae_2++;
        }
        
         //total de alta complexidade e duracao maior que 100 horas
        if (complexo==3 && offshore[i].horas>100){
            tot_alta100++;
            tot_complex++;
        }
        else{
            tot_complex++;
        }
        
        //calculo do valor do servico
        offshore[i].valor = (1200+(200*complexo*offshore[i].horas));
        
        //printando tudo
        
        printf ("%d\t%s\t%s\t%s\t%s\t%5.0fh\t $%9.2f\n", offshore[i].cod, offshore[i].os, offshore[i].unidade,offshore[i].complexidade ,offshore[i].servico,offshore[i].horas, offshore[i].valor );
        //printf ("%.0f\n", tot_servico_macae_1);
        
    }
    printf ("\n");
    
    //percentual de cada tipo de servico de macae
    perc_cal_mac= (tot_servico_macae_1/tot_servico_macae)*100;
    perc_usi_mac= (tot_servico_macae_2/tot_servico_macae)*100;
    perc_alta100 = (tot_alta100/tot_complex)*100;
    media_cal = (tot_hora_cal/tot_hora);
    media_usi= (tot_hora_usi/tot_hora);
    printf ("Percentual de caldeiraria macae: %.1f%%\n", perc_cal_mac);
    printf ("Percentual de usinagem macae: %.1f%%\n", perc_usi_mac);
    printf ("Percentual de alta complexidade com mais de 100 horas: %.1f%%\n", perc_alta100);
    printf ("Media de hora caldeiraria: %.1f\n", media_cal);
    printf ("Media de hora usinagem: %.1f\n", media_usi);
    

    printf ("\n");
    printf("======================================================\n");
    printf ("\n");
    printf ("Ordem decrescente de valor de servico: \n");
    //ordenando por valor de servico
    for (i=0; i<=149;i++){
        for (j=i+1; j<=150;j++){
            if (offshore[i].valor<offshore[j].valor){
                aux=offshore[i];
                offshore[i]= offshore[j];
                offshore[j]=aux;
            }
        }
        printf ("%d\t%s\t%s\t%s\t%s\t%5.0fh\t $%9.2f\n", offshore[i].cod, offshore[i].os, offshore[i].unidade,offshore[i].complexidade ,offshore[i].servico,offshore[i].horas, offshore[i].valor );
    }
    printf ("\n");
    printf("======================================================\n");
    printf ("\n");
    printf ("Ordem crescente de hora: \n");
    //ordenando por hora de servico
    for (i=0; i<=149;i++){
        for (j=i+1; j<=150;j++){
            if (offshore[i].horas>offshore[j].horas){
                aux=offshore[i];
                offshore[i]= offshore[j];
                offshore[j]=aux;
            }
        }
        printf ("%d\t%s\t%s\t%s\t%s\t%5.0fh\t $%9.2f\n", offshore[i].cod, offshore[i].os, offshore[i].unidade,offshore[i].complexidade ,offshore[i].servico,offshore[i].horas, offshore[i].valor);
    }
}
