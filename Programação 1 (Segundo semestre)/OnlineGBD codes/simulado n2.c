#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
    srand(time(NULL));
    struct tinformatica{
        int cod, prova_e, prova_cg;
        char cargo[15], codigo[15], curso[20], ingles[20];
        float ponto;
    };
    int i,j, car, cur, in, mAna=0, mDev=0,mScr=0;
    float tot_ana, tot_dev, tot_scr, tot_cargo, per_ana, per_dev, per_scr, tot_pontos, media_pontos;
    float tot_300, tot_qualquer, per_300;
    
     struct tinformatica empresa [147], aux;
     
     for (i=0; i<147; i++){
         empresa[i].cod = i+101;
         car= (rand()%3)+1;
         cur= (rand()%3)+1;
         in= (rand()%3)+1;
         empresa[i].prova_e = (rand()%51)+50;
         empresa[i].prova_cg=(rand()%51)+50;
         empresa[i].ponto = ((float)empresa[i].prova_e*2+(float)empresa[i].prova_cg)*(1+(float)(cur+in)/10);
         
         //cargo
         if (car==1){
            sprintf (empresa[i].codigo, "ANA%d", empresa[i].cod);
            sprintf (empresa[i].cargo, "Analista");
            tot_cargo++;
            tot_ana++;
            //descobrindo melhor analista
                if (tot_ana==1) mAna=i;
                else if (empresa[i].ponto>empresa[mAna].ponto) mAna=i;
         }
         else if (car==2){
            sprintf (empresa[i].codigo, "DES%d", empresa[i].cod);
            sprintf (empresa[i].cargo, "Desenvolvedor");
            tot_cargo++;
            tot_dev++;
            //descobrindo melhor dev
                if (tot_dev==1) mDev=i;
                else if (empresa[i].ponto>empresa[mDev].ponto) mDev=i;
         }
         else{
            sprintf (empresa[i].codigo, "SCR%d", empresa[i].cod);
            sprintf (empresa[i].cargo, "ScrumMas"); 
            tot_cargo++;
            tot_scr++;
            //descobrindo melhor ScrumMas
                if (tot_scr==1) mScr=i;
                else if (empresa[i].ponto>empresa[mScr].ponto) mScr=i;
         }
         
         
        //curso
        if (cur==1){
            sprintf (empresa[i].curso, "Cursando");
        }
        else if (cur==2){
            sprintf (empresa[i].curso, "Completo");
        }
        else{
            sprintf (empresa[i].curso, "Especializacao");
        }
        
        //ingles
        if (in==1){
            sprintf (empresa[i].ingles, "Basico       ");
        }
        else if (in==2){
            sprintf (empresa[i].ingles, "Intermediario");
        }
        else {
            sprintf (empresa[i].ingles, "Avancado     ");
        }
        
        
        //O percentual de candidatos com especialização que obtiveram pontuação superior a 300 pontos.
        if (empresa[i].ponto>300){
            tot_300++;
            tot_qualquer++;
        }
        else if (empresa[i].ponto<300){
            tot_qualquer++;
        }
        
        printf ("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%.0f\n", empresa[i].cod, empresa[i].codigo, empresa[i].cargo, empresa[i].curso, empresa[i].ingles,empresa[i].prova_e,empresa[i].prova_cg,empresa[i].ponto);
        
        tot_pontos+= empresa[i].ponto;
     }
    per_ana = (tot_ana/tot_cargo)*100; 
    per_dev = (tot_dev/tot_cargo)*100; 
    per_scr = (tot_scr/tot_cargo)*100;
    media_pontos= tot_pontos/i;
    per_300= (tot_300/tot_qualquer)*100;
    
    printf ("O percentual de Candidatos Analistas: %.1f%%\n",per_ana);
    printf ("O percentual de Candidatos Desenvolvedores: %.1f%%\n",per_dev);
    printf ("O percentual de Candidatos ScrumMas: %.1f%%\n",per_scr);
    printf ("A média da pontuacao de todos os candidatos: %.1f\n", media_pontos);
    printf ("Percentual de candidatos com especialização que obtiveram pontuação superior a 300 pontos: %.1f%%\n", per_300);
    printf ("\n");
    
    printf ("================================================================================================\n");
    printf ("Melhor Analista: \n");
    printf ("\n");
    printf ("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%.0f\n", empresa[mAna].cod, empresa[mAna].codigo, empresa[mAna].cargo, empresa[mAna].curso, empresa[mAna].ingles,empresa[mAna].prova_e,empresa[mAna].prova_cg,empresa[mAna].ponto);
    
    printf ("================================================================================================\n");
    printf ("Melhor Desenvolvedor: \n");
    printf ("\n");
    printf ("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%.0f\n", empresa[mDev].cod, empresa[mDev].codigo, empresa[mDev].cargo, empresa[mDev].curso, empresa[mDev].ingles,empresa[mDev].prova_e,empresa[mDev].prova_cg,empresa[mDev].ponto);
    
    printf ("================================================================================================\n");
    printf ("Melhor ScrumMas: \n");
    printf ("\n");
    printf ("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%.0f\n", empresa[mScr].cod, empresa[mScr].codigo, empresa[mScr].cargo, empresa[mScr].curso, empresa[mScr].ingles,empresa[mScr].prova_e,empresa[mScr].prova_cg,empresa[mScr].ponto);
    
    printf ("================================================================================================\n");
    printf ("\n");
    printf ("Ordem decrescente de valor de pontuacao final: \n");
    printf ("\n");
    for (i=0;i<=99;i++){
        for (j=i+1;j<=100;j++){
            if (empresa[i].ponto<empresa[j].ponto){
                aux=empresa[i];
                empresa[i]=empresa[j];
                empresa[j]=aux;
            }
        }
       printf ("%d\t%s\t%s\t%s\t%s\t%d\t%d\t%.0f\n", empresa[i].cod, empresa[i].codigo, empresa[i].cargo, empresa[i].curso, empresa[i].ingles,empresa[i].prova_e,empresa[i].prova_cg,empresa[i].ponto); 
    }
    

    return 0;
}