//pilha.cpp

#include "pilha.h"

void inicializar(No*& topo) {
    topo = NULL;
}

// Insere um item no topo
void push(No*& topo, int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->proximo = topo;
    topo = novo;
}

// Remove e retorna o elemento do topo 
int pop(No*& topo) {
    if (isEmpty(topo)) {
        cout << "ERROR: Pilha vazia\n";
        return -1; // indica erro
    }
    No* temp = topo;
    int valor = topo->valor;
    topo = topo->proximo;
    delete temp;
    return valor;
}

// Retorna o valor no topo da pilha sem remover
int top(No* topo) {
    if (isEmpty(topo)) {
        cout << "ERROR: Pilha vazia\n";
        return -1;
    }
    return topo->valor;
}

// Verifica se a pilha esta vazia
bool isEmpty(No* topo) {
    return topo == NULL;
}

// Retorna o tamanho da pilha
int size(No* topo) {
    int contador = 0;
    No* atual = topo;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

// Mostra todos os itens da pilha
void mostrar(No* topo) {
    No* atual = topo;
    cout << "[ ";
    while (atual != NULL) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << "]\n";
}
