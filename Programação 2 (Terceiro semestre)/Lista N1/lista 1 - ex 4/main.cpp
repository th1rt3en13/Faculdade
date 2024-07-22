//main

#include <iostream>
#include "parimpar.h"

using namespace std;
//Faca um programa capaz de armazenar um vetor estatico de 10 numeros inteiros,
//informados aleatoriamente pelo usuario. Apos isso, o programa devera apresentar um
//menu na funcao “main()” que permita as seguintes funcoes: 
//a) Exibir vetor informado;
//b) Exibir elementos impares armazenados no vetor; 
//c) Exibir elementos pares no vetor; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//menu para o usuario
char menu(){
	cout<< "\n";
	cout<< "Opcoes: \n";
	cout<< "a - Exibir vetor informado\n";
	cout<< "b - Exibir elementos impares armazenados no vetor \n";
	cout<< "c - Exibir elementos pares no vetor \n";
	cout<< "d - Encerrar o programa\n";
	char op;
	cin.get(op); //ler opcao do usuario
	return op;
}

int main(int argc, char** argv) {
	int valores[10];
	int i, num;
	//obtendo numeros para o vetor
	for (i=0; i<10; i++){
		cout << "Digite um numero: "<< endl;
		cin>>valores[i];	
	}
	char op; 
	do{
		op = menu();
		switch (op){
			case 'a': 
				//Exibir vetor informado
				for (i=0; i<10; i++){
					cout << valores[i] << " ";
   				}
				break;
				
			case 'b':
				//Exibir elementos impares armazenados no vetor
				impar(valores);
				break;
				
			case 'c':
				//Exibir elementos pares no vetor
				par(valores);
				break;
				
			case 'd':
				//Encerrar o programa
				cout<<"fim de programa\n";
				break;
				
			default:
				cout<< "letra invalida, tente novamente\n";
				break;
				
		}
		// No final do loop
		cout << "Pressione Enter para continuar...";
		cin.ignore(); // Limpa o buffer do teclado
		cin.get(); // Espera o usuário pressionar Enter

	}while (op!='d');
	
	
	return 0;
}

