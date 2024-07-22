#include <iostream>
#include "calc_esfera.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//menu usuario
int menu(){
	int op;
	cout<< "    "<<endl;
	cout<< "MENU: "<<endl;
	cout<< "1- calcular propriedades de esfera"<<endl;
	cout<< "2 - encerrar"<<endl;
	cout<< "digite a opcao desejada: ";
	cin>> op;
	return op;
}

int main(int argc, char** argv) {
	int op=0;
	float raio, area, volume;
	
	do{
		op=menu();
		switch(op){
			case 1:
				//calculo de propriedades de esfera
				cout<<"Insira o valor do raio: ";
				cin>> raio;
				calc_esfera (raio, &area, &volume);
				cout<< "O valor da area eh: "<< area<<endl;
				cout<< "O valor do volume eh: "<<volume<<endl;
				break;
			
			case 2: 
				//encerrar programa
				cout<<"Fim de programa"<<endl;
				break;
			
			default:
				cout << "Numero invalido, tente novamente" << endl;
                break;  
		}
		// No final do loop
        cout << "Pressione Enter para continuar...";
        cin.ignore(); // Limpa o buffer do teclado
        cin.get(); // Espera o usuário pressionar Enter

	}while (op!=2);
	
	return 0;
}
