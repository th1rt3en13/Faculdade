#include <iostream>
#include "Calculadora_OO.h"
using namespace std;

void menu() {
    cout << "Escolha uma opcao:\n";
    cout << "1- Soma" << endl;
    cout << "2- Subtracao" << endl;
    cout << "3- Multiplicacao" << endl;
    cout << "4- Divisao" << endl;
    cout << "5- Raiz" << endl;
    cout << "6- Potencia" << endl;
    cout << "7- Teste numero" << endl;
    cout << "8- Sair" << endl;
    cout << "Opcao: ";
}

void submenu() {
    cout << "Escolha opcao:\n";
    cout << "a- Eh par?" << endl;
    cout << "b- Eh impar?" << endl;
    cout << "c- Eh primo?" << endl;
    cout << "d- Voltar ao menu principal" << endl;
    cout << "Opcao: ";
}

float ler_numero(int i) {
    cout << "Informe N" << i << ": ";
    float tmp;
    cin >> tmp;
    return tmp;
}

void mostra_resultado(float res) {
    cout << "Resultado: " << res << endl;
}

int main() {
    Calculadora_OO teste;
    int op(0);
    float n1, n2;

    do {
        system("cls"); // limpa somente antes de mostrar o menu
        menu();
        cin >> op;

        switch (op) {
            case 1: // soma
                n1 = ler_numero(1);
                n2 = ler_numero(2);
                mostra_resultado(teste.soma(n1, n2));
                break;

            case 2: // subtracao
                n1 = ler_numero(1);
                n2 = ler_numero(2);
                mostra_resultado(teste.subtracao(n1, n2));
                break;

            case 3: // multiplicacao
                n1 = ler_numero(1);
                n2 = ler_numero(2);
                mostra_resultado(teste.multiplicacao(n1, n2));
                break;

            case 4: // divisao
                n1 = ler_numero(1);
                n2 = ler_numero(2);
                mostra_resultado(teste.divisao(n1, n2));
                break;

            case 5: // raiz
                n1 = ler_numero(1);
                n2 = ler_numero(2);
                mostra_resultado(teste.raiz(n1, n2));
                break;

            case 6: // potencia
                n1 = ler_numero(1);
                n2 = ler_numero(2);
                mostra_resultado(teste.potencia(n1, n2));
                break;

            case 7: { // testes
                char op_sub;
                do {
                	system("cls"); 
                    submenu();
                    cin >> op_sub;

                    switch (op_sub) {
                        case 'a': // par
                            n1 = ler_numero(1);
                            if (teste.par(n1))
                                cout << n1 << " eh PAR" << endl;
                            else
                                cout << n1 << " nao eh PAR" << endl;
                            break;

                        case 'b': // impar
                            n1 = ler_numero(1);
                            if (teste.impar(n1))
                                cout << n1 << " eh IMPAR" << endl;
                            else
                                cout << n1 << " nao eh IMPAR" << endl;
                            break;

                        case 'c': // primo
                            n1 = ler_numero(1);
                            if (teste.primo(n1))
                                cout << n1 << " eh PRIMO" << endl;
                            else
                                cout << n1 << " nao eh PRIMO" << endl;
                            break;

                        case 'd': // voltar
                            break;

                        default:
                            cout << "Opcao invalida!" << endl;
                    }

                    if (op_sub != 'd') {
                        cout << "Pressione ENTER para continuar..."<<endl;
                        cin.ignore();
                        cin.get();
                    }

                } while (op_sub != 'd');

                break;
            }

            case 8:
                cout << "Fim de programa!" << endl;
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }

        if (op != 8) {
            cout << "Pressione ENTER para voltar ao menu..."<<endl;
            cin.ignore();
            cin.get();
        }

    } while (op != 8);

    return 0;
}

