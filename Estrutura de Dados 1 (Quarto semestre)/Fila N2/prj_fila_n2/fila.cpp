//fila.cpp
#include "fila.h"

// Inicializa a fila 
void inicializar(No*& inicio, No*& fim) {
    inicio = NULL;
    fim = NULL;
}

// Insere um elemento no fim da fila
void enqueue(No*& inicio, No*& fim, int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (isEmpty(inicio)) {
        inicio = novo;  
    } else {
        fim->proximo = novo;  
    }
    fim = novo;  
}


int dequeue(No*& inicio, No*& fim) {
    if (isEmpty(inicio)) {
        cout << "ERROR: Fila vazia\n";
        return -1; // indica o erro
    }
    No* temp = inicio;
    int valor = inicio->valor;
    inicio = inicio->proximo;
    
    if (inicio == NULL) {
        fim = NULL;  // Se a fila ficou vazia, fim recebe null
    }
    
    delete temp;
    return valor;
}


int front(No* inicio) {
    if (isEmpty(inicio)) {
        cout << "ERROR: Fila vazia\n";
        return -1;
    }
    return inicio->valor;
}


bool isEmpty(No* inicio) {
    return inicio == NULL;
}

// Retornar o tamanho da fila
int size(No* inicio) {
    int contador = 0;
    No* atual = inicio;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

// Mostrar todos os elementos da fila
void mostrar(No* inicio) {
    No* atual = inicio;
    cout << "[ ";
    while (atual != NULL) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << "]\n";
}
