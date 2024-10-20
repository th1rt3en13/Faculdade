//main
#include "pilha.h"

int main() {
    No* pilha;
    inicializar(pilha);  

    //exemplo
    push(pilha, 5);
    mostrar(pilha);  // [ 5 ]

    push(pilha, 3);
    mostrar(pilha);  // [ 5, 3 ]

    cout << "pop(): " << pop(pilha) << endl;  
    mostrar(pilha);  // [ 5 ]

    push(pilha, 7);
    mostrar(pilha);  // [ 5, 7 ]

    cout << "pop(): " << pop(pilha) << endl;  
    mostrar(pilha);  // [ 5 ]

    cout << "top(): " << top(pilha) << endl;  

    cout << "pop(): " << pop(pilha) << endl;  
    mostrar(pilha);  // [ ]

    cout << "pop(): " << pop(pilha) << endl;  // ERRO: Pilha vazia

    cout << "isEmpty(): " << (isEmpty(pilha) ? "TRUE" : "FALSE") << endl;  // isEmpty(): TRUE

    push(pilha, 9);
    push(pilha, 7);
    push(pilha, 3);
    push(pilha, 5);
    mostrar(pilha);  // [ 9, 7, 3, 5 ]

    cout << "size(): " << size(pilha) << endl;  

    cout << "pop(): " << pop(pilha) << endl;  
    mostrar(pilha);  // [ 9, 7, 3 ]

    push(pilha, 8);
    mostrar(pilha);  // [ 9, 7, 3, 8 ]

    cout << "pop(): " << pop(pilha) << endl;  
    mostrar(pilha);  // [ 9, 7, 3 ]

    cout << "pop(): " << pop(pilha) << endl;  
    mostrar(pilha);  // [ 9, 7 ]

    return 0;
}
