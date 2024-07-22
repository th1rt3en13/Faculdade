#include <iostream>
#include "funcoes.h"

using namespace std;

int menu() {
    int op;
    cout << endl;
    cout << "MENU:" << endl;
    cout << "1- Cadastrar turma;" << endl;
    cout << "2- Imprimir dados;" << endl;
    cout << "3- Encerrar programa;" << endl;
    cout << "Escolha: ";
    cin >> op;
    return op;
}

int main(int argc, char** argv) {
    int op;
    turma* t = NULL;
    do {
        op = menu();
        switch (op) {
            case 1:
                // cadastrar turma
                t = cadastrar_turma(t);
                break;

            case 2:
                // imprimir dados
                imprimir_turma(t);
                break;

            case 3:
                // encerrar programa
                cout << "Fim de Programa!" << endl;
                desalocar(t);
                break;

            default:
                // opcao invalida
                cout << "Opcao invalida, tente novamente!" << endl;
        }
    } while (op != 3);

    return 0;
}

