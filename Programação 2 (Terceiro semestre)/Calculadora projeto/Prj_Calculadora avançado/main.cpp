#include <iostream>
#include "calculadora.h"
#include "calculadora_av.h"
#include "teste_num.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(){
	cout << "\n";
	cout << "Calculadora:\n";
	cout << "1-Soma\n";
	cout << "2-Subtracao\n";
	cout << "3-Multiplicacao\n";
	cout << "4-Divisao\n";
	cout << "5-Potenciacao\n";
	cout << "6-Radiciacao\n";
	cout << "------------------\n";
	cout << "Testes de numero\n";
	cout << "7-Eh par\n";
	cout << "8-Eh impar\n";
	cout << "9-Eh primo\n";
	cout << "Digite qualquer outro numero para sair\n";
	int op;
	cin >> op; //ler opcao do usuario
	return op;
}

float obter_num(int n){
	cout << "Digite n" << n<<": ";
	float r;
	cin >> r;
	return r;
}
//optei por nao limitar as casa decimais do float pois em uma calculadora aparece todas as casas decimais

int main(int argc, char** argv) {
	int op(0);
	float resp, n1, n2;
	do{
		op = menu();
		switch (op){
			case 1:
				//soma
				n1=obter_num(1);
				n2=obter_num(2);
				resp=soma(n1,n2);
				cout << "soma eh: "<< resp<<endl;
				break;
			case 2:
				//subtracao
				n1=obter_num(1);
				n2=obter_num(2);
				resp=subtracao(n1,n2);
				cout << "subtracao eh: "<< resp<<endl;
				break;
			case 3: 
				//multiplicacao
				n1=obter_num(1);
				n2=obter_num(2);
				resp=multiplicacao(n1,n2);
				cout << "multiplicacao eh: "<< resp<<endl;
				break;
			case 4:
				//divisao
				n1=obter_num(1);
				n2=obter_num(2);
				resp=divisao(n1,n2);
				cout << "divisao eh: "<< resp<<endl;
				break;
			case 5:
				//potenciacao
				n1=obter_num(1);
				n2=obter_num(2);
				resp=potencia(n1,n2);
				cout << "potenciacao eh: "<< resp<<endl;
				break;
			case 6:
				//radiciacao
				n1=obter_num(1);
				n2=obter_num(2);
				resp=raiz(n1,n2);
				cout << "radiciacao eh: "<<resp<<endl;
				break;
			case 7:
				//eh par
				n1=obter_num(1);
				resp=eh_par(n1);
				if (resp == 1){
					cout<< "eh par: sim "<<endl;
				}
				else{
					cout<< "eh par: nao "<<endl;
				}
				break;
			case 8: 
				//eh impar
				n1=obter_num(1);
				resp=eh_impar(n1);
				if (resp ==  1){
					cout<< "eh impar: sim "<<endl;	
				}
				else {
					cout<< "eh impar: nao "<<endl;	
				}
				break;
			case 9:
				//eh primo
				n1=obter_num(1);
				resp=eh_primo(n1);
				if (resp == 1){
					cout<< "eh primo: sim "<<endl;	
				}
				else{
					cout<< "eh primo: nao"<<endl;
				}
				break;
			default:
				//fim de programa
				cout<<"fim de programa\n";
		}
		system("pause");
		
	}while ((op<=9)&&(op>=1));
	
	

	return 0;
}
