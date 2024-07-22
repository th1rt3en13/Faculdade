#include <iostream>
#include "funcoes.h"
using namespace std;

int menu() {
    int op;
    cout << "MENU: " << endl;
    cout << "1- Cadastrar aluno" << endl;
    cout << "2- Imprimir cadastro" << endl;
    cout << "3- Salvar em arquivo" << endl;
    cout << "4- Carregar em arquivo" << endl;
    cout << "5- Sair do programa" << endl;
    cout << "Digite a opcao: ";
    cin >> op;
    cout << endl;
    return op;
}

int main(int argc, char** argv) {
    int op = 0;
    Aluno* aluno = NULL; // Ponteiro para armazenar o cadastro de um aluno
    
    do {
        op = menu();
        switch (op) {
            case 1:
                // Cadastrar aluno novo
                if (aluno != NULL) {
                    cout << "Ja existe um aluno cadastrado!\n";
                } else {
                    aluno = cadastrar_aluno();
                }
                break;

            case 2:
                // Exibir aluno cadastrado
                if (aluno != NULL) {
                    exibir_aluno(aluno);
                } else {
                    cout << "Nenhum aluno cadastrado!\n";
                }
                break;

            case 3:
                // Salvar aluno em arquivo
                if (aluno != NULL) {
                    salvar_em_arquivo(aluno, "aluno.txt");
                } else {
                    cout << "Nenhum aluno cadastrado para salvar!\n";
                }
                break;

            case 4:
                // Carregar aluno de arquivo
                if (aluno != NULL) {
                    desalocar_aluno(aluno);
                }
                aluno = carregar_de_arquivo("aluno.txt");
                break;

            case 5:
                // Desalocar e encerrar programa
                desalocar_aluno(aluno);
                cout << "Fim de Programa!" << endl;
                break;

            default:
                // Opcao invalida
                cout << "Opcao invalida, tente novamente!" << endl;
        }
        // No final do loop
        cout << "Pressione Enter para continuar...";
        cin.ignore(); // Limpa o buffer do teclado
        cin.get(); // Espera o usuário pressionar Enter
    } while (op != 5);

    return 0;
}
