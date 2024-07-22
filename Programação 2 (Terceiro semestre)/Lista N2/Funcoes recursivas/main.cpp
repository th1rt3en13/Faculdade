//main.cpp
#include <iostream>
#include "funcoes.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(){
	int op;
	cout<<endl;
	cout<<"MENU: "<<endl;
	cout<< "1- Cadastrar aluno (nome e nota)"<<endl;
	cout<< "2- Imprimir alunos cadastrados"<<endl;
	cout<< "3- Imprimir alunos aprovados (nota >= 7)"<<endl;
	cout<<"4- Imprimir alunos em final (nota < 7)"<<endl;
	cout<<"5- Exibir quantidade alunos cadastrados"<<endl;
	cout<<"6- Exibir quantidade alunos aprovados"<<endl;
	cout<<"7- Exibir quantidade alunos em final"<<endl;
	cout<<"8- Sair"<<endl;
	cout<<"Escolha: ";
	cin>>op;
	return op;
}

int main(int argc, char** argv) {
	aluno *a = 0;
	int cont =0;
	int op(0);//contar alunos cadastrados
	do{
		op=menu();
		switch (op){
			case 1:
				a= cadastrar_aluno(&cont, a);
				//cadastrar
				break;
			
			case 2:
				//imprimir cadastrados
				//funcao com recursividade
				if (cont==0){
					cout<<"Nenhum aluno cadastrado"<<endl;
				}
				else{
					alunos_cadastrados(0,cont,a);
				}
				break;
				
			case 3:
				//imprimir aprovados
				//funcao com recursividade
				if (cont==0){
					cout<<"Nenhum aluno cadastrado"<<endl;
					cout<<endl;
				}
				else{
					alunos_cadastrados_aprov(0,cont,a);
				}
				break;
		
			case 4:
				//imprimir de final
				//funcao com recursividade
				if (cont==0){
					cout<<"Nenhum aluno cadastrado"<<endl;
					cout<<endl;
				}
				else{
					alunos_cadastrados_repr(0,cont,a);
				}
				break;
				
			case 5:
				//exibir quantidade cadastrada
				//funcao com recursividade
				cout<< "Total de alunos = "<<quant_total(0,cont,a);
				cout<<endl;
				break;
				
			case 6:
				//exibir quantidade aprovados
				//funcao com recursividade
				cout<< "Total de alunos aprovados = "<<quant_aprov(0,cont,a);
				cout<<endl;
				break;
				
			case 7:
				//exibir quantidade de final
				//funcao com recursividade
				cout<< "Total de alunos reprovados = "<<quant_repr(0,cont,a);
				cout<<endl;
				break;
				
			case 8: 
				//sair
				a = desalocar(&cont, a);
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
	}while (op!=8);
		return 0;
	}
	
	
	

