//main.cpp 

#include "fila.h"

int main() {
    No* inicio;
    No* fim;
    inicializar(inicio, fim);  // Inicializa a fila

	//EXEMPLO
    enqueue(inicio, fim, 5);
    mostrar(inicio);  // [ 5 ]

    enqueue(inicio, fim, 3);
    mostrar(inicio);  // [ 5, 3 ]

    cout << "dequeue(): " << dequeue(inicio, fim) << endl;  // dequeue(): 5
    mostrar(inicio);  // [ 3 ]

    enqueue(inicio, fim, 7);
    mostrar(inicio);  // [ 3, 7 ]

    cout << "dequeue(): " << dequeue(inicio, fim) << endl;  // dequeue(): 3
    mostrar(inicio);  // [ 7 ]

    cout << "front(): " << front(inicio) << endl;  // front(): 7

    cout << "dequeue(): " << dequeue(inicio, fim) << endl;  // dequeue(): 7
    mostrar(inicio);  // [ ]

    cout << "dequeue(): " << dequeue(inicio, fim) << endl;  // ERRO: Fila vazia

    cout << "isEmpty(): " << (isEmpty(inicio) ? "TRUE" : "FALSE") << endl;  // isEmpty(): TRUE

    enqueue(inicio, fim, 9);
    enqueue(inicio, fim, 7);
    mostrar(inicio);  // [ 9, 7 ]

    cout << "size(): " << size(inicio) << endl;  // size(): 2

    enqueue(inicio, fim, 3);
    enqueue(inicio, fim, 5);
    mostrar(inicio);  // [ 9, 7, 3, 5 ]

    cout << "dequeue(): " << dequeue(inicio, fim) << endl;  
    mostrar(inicio);  // [ 7, 3, 5 ]

    return 0;
}
