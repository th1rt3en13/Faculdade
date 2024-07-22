// cadastro.cpp
#include "cadastro.h"
using namespace std;

int cadastrar_num(int *cont, int *&aux) { //sem & qualquer alteracao nao eh refletida fora de cadastras_num
    (*cont)++;
    if (*cont == 1) {
        // Primeira aloca��o
        aux = (int*) malloc(sizeof(int));
    } else {
        // Realoca��o para acomodar mais n�meros
        aux = (int*) realloc(aux, *cont * sizeof(int));
    }
    // Solicita ao usu�rio que insira o n�mero
    cout << "Informe o numero: ";
    cin >> aux[*cont - 1]; // Armazena o n�mero no array
    //cout << "Numero cadastrado: " << aux[*cont - 1] << endl; teste
    cout << endl;
    return *aux;
}

void exibir_num(int *cont, int *aux) {
    // Verificar se h� n�meros cadastrados
    if (*cont == 0) {
        cout << "Nenhum n�mero cadastrado." << endl;
        return;
    }
    // Exibir os n�meros cadastrados
    cout << "Numeros cadastrados: ";
    for (int i = 0; i < *cont; i++) {
        cout << aux[i] << " ";
    }
    cout << endl;
}

void excluir_num (int *cont, int *aux){
	if (*cont == 0) {
		cout<<"nenhum numero cadastrado"<< endl;
		return;
	}
	(*cont)--; //decrementar o contador pois estou excluindo
	aux = (int*) realloc(aux, *cont * sizeof(int));
	//conferindo
	if (*cont > 0) {
        cout << "Ultimo numero removido: " << aux[*cont] << endl;
    }
}


