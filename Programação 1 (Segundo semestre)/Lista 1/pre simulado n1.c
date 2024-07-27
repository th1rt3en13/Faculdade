//belbet e livian
//1 - Fazer um programa que crie e apresente para os 105 clientes
//    • Código do cliente um sequencial a partir de 1001
//    • Tipo de cliente (1 – Residencial 2 – Comercial ou 3 - Rural); 
//    • Link (60mb, 150mb ou 300mb); 
//    • Região (1 – Sana, 2 – Frade ou 3 - Glicério); 
//    • Consumo de internet móvel (5gb a 20gb) Mês 1; 
//    • Consumo de internet móvel (5gb a 20gb) Mês 2; 
//    • Consumo de internet móvel (5gb a 20gb) Mês 3; 
//    • Consumos total e mensal deverão ser calculados


//pacotes de biblioteca c
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//funcao principal do programa
int main()
{
    int i=0, cliente,tipo_cliente, regiao, mes1, mes2, mes3, link, maior=0;
    char tipo_de_cliente[20], regioes[20], tipo_link[10];
    float media, total, media1,media2,media3, tot1,tot2,tot3, totlink1, totlink2, totlink3, perc1, perc2, perc3;
    //funcao para permitir que o rand gere novos valores todas as vezes
    srand(time(NULL));
    
    //estrutura de repeticao
    printf ("cod.:\tcliente:\tlink:\treg:\t\t\tmes1:\tmes2:\tmes3:\ttotal:\tmedia:\tmed1:\tmed2:\tmed3:\tperc1:\tperc2:\tperc3\n");
    while (i<105){
        i++;
        //randomicos
        cliente = (rand()%105)+1;
        tipo_cliente=(rand()%3)+1;
        regiao = (rand()%3)+1;
        link= (rand()%3)+1;
        mes1= (rand()%16)+5;
        mes2= (rand()%16)+5;
        mes3= (rand()%16)+5;
        cliente+=1000;
        
        if (tipo_cliente==1){ //condiconal para verificar o tipo de residência
            sprintf(tipo_de_cliente,"Residencial ");
        }
        else if (tipo_cliente==2){//condiconal para verificar o tipo de residência
            sprintf (tipo_de_cliente, "Comercial ");
        }
        else{//condiconal para verificar o tipo de residência
            sprintf(tipo_de_cliente, "Rural      ");
        }
       
        if (link==1){//condiconal para verificar o tipo de link
           sprintf(tipo_link, "60mb"); 
           totlink1++;
        }
        else if (link==2){//condiconal para verificar o tipo de link
           sprintf(tipo_link, "150mb");
           totlink2++;
        }
        else{//condiconal para verificar o tipo de link
           sprintf(tipo_link, "300mb"); 
           totlink3++;
        }
        if (regiao==1){//condiconal para verificar o tipo de regiao
            sprintf(regioes, "Sana\t\t");
            tot1+=mes1;
        }
        else if (regiao==2){//condiconal para verificar o tipo de regiao
            sprintf (regioes, "Frade\t\t");
            tot2+=mes2;
        }
        else{//condiconal para verificar o tipo de regiao
            sprintf(regioes, "Glicério\t");
            tot3+=mes3;
        }
        //calculo de total de consumo dos meses
        total = mes1+ mes2+mes3;
        
        if (total>maior){//condicional para saber maior consumo
            maior=cliente;
        }
        perc1= (totlink1/i)*100;//percentual do link 1
        perc2= (totlink2/i)*100;//percentual do link 2
        perc3= (totlink3/i)*100;//percentual do link 3
        media=total/3;//calculo de media trimestral
        media1=tot1/total;//calculo de media mes 1
        media2=tot2/total;//calculo de media mes 2
        media3=tot3/total;//calculo de media mes 3
        printf ("%d\t %s\t %s\t %s\t %dgb\t %dgb\t %dgb\t %.0fgb   %.1fgb\t %.1fgb\t %.1fgb\t %.1fgb\n",cliente, tipo_de_cliente, tipo_link, regioes, mes1, mes2, mes3, total, media, media1, media2, media3);
        
        
    }
    printf("\n");
    printf ("Cliente com maior consumo: %d\n", maior);
    printf("Percentual link 1: %.1f\n%%", perc1);
    printf("Percentual link 1: %.1f\n%%", perc2);
    printf("Percentual link 1: %.1f\n%%", perc3);
    
       
    
}
