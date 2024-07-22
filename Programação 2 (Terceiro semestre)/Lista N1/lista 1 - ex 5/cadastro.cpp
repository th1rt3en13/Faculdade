// cadastro.cpp
#include "cadastro.h"
using namespace std;

int cadastrar_num(int *cont, int *&aux) { //sem & qualquer alteracao nao eh refletida fora de cadastras_num
    (*cont)++;
    if (*cont == 1) {
        // Primeira alocação
        aux = (int*) malloc(sizeof(int));
    } else {
        // Realocação para acomodar mais números
        aux = (int*) realloc(aux, *cont * sizeof(int));
    }
    // Solicita ao usuário que insira o número
    cout << "Informe o numero: ";
    cin >> aux[*cont - 1]; // Armazena o número no array
    //cout << "Numero cadastrado: " << aux[*cont - 1] << endl; teste
    cout << endl;
    return *aux;
}

void exibir_num(int *cont, int *aux) {
    // Verificar se há números cadastrados
    if (*cont == 0) {
        cout << "Nenhum número cadastrado." << endl;
        return;
    }
    // Exibir os números cadastrados
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


