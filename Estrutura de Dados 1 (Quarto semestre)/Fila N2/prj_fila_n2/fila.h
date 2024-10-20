//fila.h
#include <iostream>
using namespace std;

// struct do no
struct No {
    int valor;
    No* proximo;
};

void inicializar(No*& inicio, No*& fim);  // Inicializa a fila
void enqueue(No*& inicio, No*& fim, int valor);  // Insere um elemento na fila
int dequeue(No*& inicio, No*& fim);       // Remove o primeiro elemento da fila
int front(No* inicio);                    // Retorna o valor no início da fila sem remover
bool isEmpty(No* inicio);                 // Verifica se a fila está vazia
int size(No* inicio);                     // Retorna o tamanho da fila
void mostrar(No* inicio);                 // Mostra todos os elementos da fila
