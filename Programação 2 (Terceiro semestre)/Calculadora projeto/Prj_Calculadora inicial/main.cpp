//#include <iostream> eh o include do c++ que junta o stdio.h e o stdlib.h
#include <stdio.h> //para o printf e o scanf
#include <stdlib.h> //para o system pause
#include "calculadora.h" //para importar a funcao, sempre o .h

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float n1(0), n2(0), res(0);
	
	printf("Informe numero 1: ");
	scanf("%f", &n1);
	printf("Informe numero 2: ");
	scanf("%f", &n2);
	//ctrl+/+space
	res = soma(n1,n2);
	printf ("soma de %f e %f =  %.2f\n", n1, n2, res);
	
	res = subtracao(n1,n2);
	printf ("subtracao de %f e %f =  %.2f\n", n1, n2, res);
	
	res = multiplicacao(n1,n2);
	printf ("multiplicacao de %f e %f =  %.2f\n", n1, n2, res);
	
	res = divisao(n1,n2);
	printf ("divisao de %f e %f =  %.2f\n", n1, n2, res);
	
	system("pause");
	return 0;
}