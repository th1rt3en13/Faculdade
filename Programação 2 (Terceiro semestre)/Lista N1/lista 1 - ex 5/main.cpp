// main.cpp
#include <iostream>
#include "cadastro.h"
using namespace std;

int menu() {
    int op;
    cout << endl;
    cout << "Menu: " << endl;
    cout << "1- Cadastrar numero" << endl;
    cout << "2- Exibir numero(s) cadastrados" << endl;
    cout << "3- Exibir quantidade de numeros cadastrados" << endl;
    cout << "4- Remover ultimo numero cadastrado" << endl;
    cout << "5- Sair" << endl;
    cout << "Digite: ";
    cin >> op; // Ler op��o do usu�rio
    cout << endl;
    return op;
}

int main(int argc, char** argv) {
    int op;
    int* a = NULL;
    int conta = 0;

    do {
        op = menu();
        switch(op) {
            case 1:
                // Cadastrar n�mero;
                cadastrar_num(&conta, a);
                break;
            
            case 2:
                // Exibir n�mero(s) cadastrados;
                exibir_num(&conta, a);
                break;
            
            case 3:
                // Exibir quantidade de n�meros cadastrados
                cout << "Total de numeros cadastrados: " << conta << endl << endl;
                break;
                
            case 4:
                // Remover �ltimo n�mero cadastrado
                excluir_num (&conta, a);
                break;
                
            case 5: 
                // Encerrar o programa
                cout << "Fim do programa!" << endl;
                break;

            default:
                cout << "Numero invalido, tente novamente" << endl;
                break;  
        }
        // No final do loop
        cout << "Pressione Enter para continuar...";
        cin.ignore(); // Limpa o buffer do teclado
        cin.get(); // Espera o usu�rio pressionar Enter
        
    } while (op != 5);

    // Libera a mem�ria alocada
    free(a);

    return 0;
}


