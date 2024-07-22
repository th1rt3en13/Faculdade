#include <stdio.h>
main(){
    float sal, prestacao, por;
    
    printf("salario: ");
    scanf("%f", &sal);
    
    printf("prestacao: ");
    scanf("%f", &prestacao);
    
    por = sal * 0.3; 
    
    if (prestacao > por) { 
        printf("emprestimo recusado");
    } else {
        printf("emprestimo aprovado");
    }
}
