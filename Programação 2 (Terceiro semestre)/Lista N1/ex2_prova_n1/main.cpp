#include <iostream>
#include "cadastrando.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu (){
	int op;
	cout << "MENU: "<<endl;
	cout << "1- Cadastrar novo aluno"<<endl;
	cout << "2- Exibir cadastros"<<endl;
	cout << "3- Sair do programa" << endl;
	cout<<"Digite a opcao: ";
	cin>>op;
	cout<<endl;
	return op;
}


int main(int argc, char** argv) {
	int op (0); 
	Aluno *aluno = NULL; //vetor dinamico para cadastrar alunos
	 
	do{
		op = menu ();
		switch (op){
			case 1:
				//cadastrar aluno novo
				if (aluno != NULL) {
                	cout << "Ja existe um aluno cadastrado!\n";
            	} 
				else {
				aluno = cadastrar_aluno();
				}
				break;
				
			case 2:
				//exibir aluno cadastrado
			if (aluno != NULL) {
				exibir_aluno(aluno);
            } 
			else {
                cout << "Nenhum aluno cadastrado!\n";
            }
				break;
				
			case 3:
				cout << "Fim de Programa!"<<endl;
				break;
				
			default:
				//digitou errado
				cout<< "Opcao invalida, tente novamente!"<<endl;
		}
		 // No final do loop
        cout << "Pressione Enter para continuar...";
        cin.ignore(); // Limpa o buffer do teclado
        cin.get(); // Espera o usu rio pressionar Enter
	}while (op!=3);
	
	// Libera memória
    free(aluno);
	
	return 0;
}

