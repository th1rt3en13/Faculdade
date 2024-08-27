#include <iostream>
#include "calculadora.h"
#include "teste_num.h"
using namespace std;

int menu (){
	int op;
	cout<< "CALCULADORA"<<endl;
	cout<< endl;
	cout<< "0 - Sair"<<endl;
	cout<< "1 - Soma"<<endl;
	cout<< "2 - Subtracao"<<endl;
	cout<< "3 - Multiplicacao"<<endl;
	cout<< "4 - Divisao"<<endl;
	cout<< "5 - Potenciacao"<<endl;
	cout<< "6 - Radiciacao"<<endl;
	cout<< endl;
	cout<< "TESTES"<<endl;
	cout<< endl;
	cout<< "7 - Eh par?"<<endl;
	cout<< "8 - Eh impar?"<<endl;
	cout<< "9 - Eh primo?"<<endl;
	cin>> op;
	return op;
}

float obter_numero(int num){
	cout<<"Digite o numero "<<num<<":"<<endl;
	float n;
	cin>>n;
	return n;
}

int obter_numero_inteiro(int num){
	cout<<"Digite o numero "<<num<<":"<<endl;
	int n;
	cin>>n;
	return n;
}

int main(int argc, char** argv) {
	int opcao = 0;
	float num1 = 0, num2 = 0, resp = 0;

	do {
		opcao = menu();
		switch(opcao){
			case 0:
				cout << "Fim de programa" << endl;
				break;
			case 1:
				num1 = obter_numero(1);
				num2 = obter_numero(2);
				resp = soma(num1, num2);
				cout << "Soma: " << resp << endl;
				break;
			case 2:
				num1 = obter_numero(1);
				num2 = obter_numero(2);
				resp = subtracao(num1, num2);
				cout << "Subtracao: " << resp << endl;
				break;
			case 3:
				num1 = obter_numero(1);
				num2 = obter_numero(2);
				resp = multiplicacao(num1, num2);
				cout << "Multiplicacao: " << resp << endl;
				break;
			case 4:
				num1 = obter_numero(1);
				num2 = obter_numero(2);
				resp = divisao(num1, num2);
				cout << "Divisao: " << resp << endl;
				break;
			case 5:
				num1 = obter_numero(1);
				num2 = obter_numero(2);
				resp = potencia(num1, num2);
				cout << "Potenciacao: " << resp << endl;
				break;
			case 6:
				num1 = obter_numero(1);
				num2 = obter_numero(2);
				resp = raiz(num1, num2);
				cout << "Radiciacao: " << resp << endl;
				break;
			case 7:
				num1 = obter_numero_inteiro(1);
				if (eh_par(num1)){
					cout << "Eh par" << endl;
				} else {
					cout << "Nao eh par" << endl;
				}
				break;
			case 8:
				num1 = obter_numero_inteiro(1);
				if (eh_impar(num1)){
					cout << "Eh impar" << endl;
				} else {
					cout << "Nao eh impar" << endl;
				}
				break;
			case 9:
				num1 = obter_numero_inteiro(1);
				if (eh_primo(num1)){
					cout << "Eh primo" << endl;
				} else {
					cout << "Nao eh primo" << endl;
				}
				break;
			default:
				cout << "Opcao invalida, digite novamente" << endl;
				break;
		}
	} while(opcao != 0);

	return 0;
}
