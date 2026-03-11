#include "Lista.h"

int menu(){

	int op;

	cout << "\n===== MENU LISTA =====\n";
	cout << "1 - Inserir inicio\n";
	cout << "2 - Inserir fim\n";
	cout << "3 - Remover inicio\n";
	cout << "4 - Remover fim\n";
	cout << "5 - Remover valor\n";
	cout << "6 - Buscar valor\n";
	cout << "7 - Imprimir inicio\n";
	cout << "8 - Imprimir fim\n";
	cout << "9 - Mostrar tamanho\n";
	cout << "0 - Sair\n";

	cout << "Escolha: ";
	cin >> op;

	return op;
}

int main(){

	Lista* l = new Lista();

	int op;
	int valor;

	do{

		op = menu();

		switch(op){

		case 1:

			cout << "Digite o valor: ";
			cin >> valor;
			l->insere_inicio(valor);
			cout << "Valor inserido no inicio.\n";

		break;

		case 2:

			cout << "Digite o valor: ";
			cin >> valor;
			l->insere_fim(valor);
			cout << "Valor inserido no fim.\n";

		break;

		case 3:

			if(l->vazia())
				cout << "Lista vazia! Nada para remover.\n";
			else{
				l->retira_inicio();
				cout << "Primeiro elemento removido.\n";
			}

		break;

		case 4:

			if(l->vazia())
				cout << "Lista vazia! Nada para remover.\n";
			else{
				l->retira_fim();
				cout << "Ultimo elemento removido.\n";
			}

		break;

		case 5:

			if(l->vazia()){
				cout << "Lista vazia! Nada para remover.\n";
			}
			else{

				cout << "Digite o valor: ";
				cin >> valor;

				if(l->retira(valor))
					cout << "Valor removido da lista.\n";
				else
					cout << "Valor nao encontrado.\n";
			}

		break;

		case 6:

			if(l->vazia()){
				cout << "Lista vazia! Nenhum valor para buscar.\n";
			}
			else{

				cout << "Digite o valor: ";
				cin >> valor;

				if(l->busca(valor))
					cout << "Valor encontrado.\n";
				else
					cout << "Valor nao encontrado.\n";
			}

		break;

		case 7:

			if(l->vazia())
				cout << "Lista vazia! Nada para imprimir.\n";
			else
				l->imprime_inicio();

		break;

		case 8:

			if(l->vazia())
				cout << "Lista vazia! Nada para imprimir.\n";
			else
				l->imprime_fim();

		break;

		case 9:

			if(l->vazia())
				cout << "Lista vazia! Tamanho = 0\n";
			else
				cout << "Tamanho da lista: " << l->tamanho() << endl;

		break;

		case 0:
			cout << "Encerrando programa...\n";
		break;

		default:
			cout << "Opcao invalida!\n";

		}

	}while(op != 0);

	delete l;

	return 0;
}
