//pilha.h

#include <iostream>
using namespace std;

struct No {
    int valor;   
    No* proximo; // Ponteiro para o proximo
};

void inicializar(No*& topo);           // Inicializa a pilha
void push(No*& topo, int valor);       // Inserir um elemento na pilha
int pop(No*& topo);                    // Remover o topo da pilha
int top(No* topo);                     // Retornar o valor no topo sem remover
bool isEmpty(No* topo);                // Verificar se a pilha está vazia
int size(No* topo);                    // Retornar o tamanho da pilha
void mostrar(No* topo);                // Mostrar todos os elementos da pilha

