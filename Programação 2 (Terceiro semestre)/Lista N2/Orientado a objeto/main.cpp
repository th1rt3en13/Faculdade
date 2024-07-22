#include "Turma.h"
#include <iostream>
using namespace std;

int menu() {
    int op;
    cout << "\nMENU:\n";
    cout << "1- Cadastrar turma;\n";
    cout << "2- Imprimir dados;\n";
    cout << "3- Encerrar programa;\n";
    cout << "Escolha: ";
    cin >> op;
    return op;
}

int main() {
    Turma turma;
    int opcao;

    do {
        opcao = menu();

        switch (opcao) {
            case 1:
                turma.cadastrarTurma();
                break;
            case 2:
                turma.imprimirTurma();
                break;
            case 3:
                cout << "Fim de programa...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 3);

    turma.desalocar();
    return 0;
}


