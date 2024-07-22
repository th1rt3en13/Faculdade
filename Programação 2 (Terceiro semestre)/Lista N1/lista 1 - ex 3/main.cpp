//main.cpp
#include <iostream>
#include "parte_inteiro.h"
using namespace std;

//Crie um programa capaz de capturar um número “float num” informado pelo usuário
//via “main()”, e assim invocar a função na forma prototipada a seguir:
//void decomp_fracao(float* num, int* inteiro, float* frac);
//deverá exibir a parte inteira (a partir do ponteiro “inteiro”) e a parte fracionária
//(ponteiro “frac”). Exemplo: num = 5.73, logo parte inteira = 5 e parte fracionária 0.73.

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float obter_num(){
	float numero;
	cout<<"Digite um numero decimal: ";
	cin>> numero;
	return numero;
}

int main(int argc, char** argv) {
	float num, fra;
	int inteiro;
	num = obter_num();
	decomp_fracao(&num, &inteiro, &fra);
	cout<< "parte inteira: "<<inteiro<<endl;
	cout<< "parte fracionaria: "<<fra<<endl;
	
	return 0;
}