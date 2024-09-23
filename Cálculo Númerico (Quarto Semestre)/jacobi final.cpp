#include <iostream>
#include <cmath>

using namespace std;

const int MAX_TENTATIVAS = 1000; // N�mero m�ximo de itera��es
const double ERRO_TOLERAVEL = 0.0001; // Toler�ncia para o crit�rio de parada - erro

// Fun��o para verificar se a matriz tem diagonal dominante
bool matrizDiagonalDominante(double** sistema, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        double soma_linha = 0;
        for (int j = 0; j < tamanho; j++) {
            if (i != j) {
                soma_linha += fabs(sistema[i][j]); // Soma dos elementos fora da diagonal
            }
        }
        if (fabs(sistema[i][i]) <= soma_linha) {
            return false; // N�o � diagonal dominante
        }
    }
    return true; // � diagonal dominante
}

// Fun��o para trocar as linhas da matriz quando necess�rio
void alterarLinhas(double** sistema, int tamanho, int linha1, int linha2) {
    for (int i = 0; i < tamanho + 1; i++) {
        swap(sistema[linha1][i], sistema[linha2][i]); // Troca elementos entre as linhas
    }
}

// Fun��o para reorganizar a matriz para garantir diagonal dominante
void reorganizarParaDominante(double** sistema, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (fabs(sistema[i][i]) < fabs(sistema[i][(i + 1) % tamanho]) || 
            fabs(sistema[i][i]) < fabs(sistema[i][(i + 2) % tamanho])) {
            alterarLinhas(sistema, tamanho, i, (i + 1) % tamanho); // Tenta trocar linhas adjacentes
        }
    }
}

//exemplo
//Digite o tamanho da matriz de coeficientes do sistema: 3
//Insira os coeficientes da matriz e os termos independentes (linha por linha):
//10 2 -1 27
//-3 -6 2 -61.5
//1 1 5 -21.5

// Fun��o para aplicar o m�todo de Gauss-Jacobi
void resolverGaussJacobi(double** sistema, int tamanho, double* resultado) {
    double* solucaoAnterior = new double[tamanho]; // Vetor para armazenar a solu��o anterior
    for (int i = 0; i < tamanho; i++) {
        solucaoAnterior[i] = 0; // Inicializa com zero
    }

    // Verifica se a matriz � diagonal dominante
    if (!matrizDiagonalDominante(sistema, tamanho)) {
        cout << "A matriz n�o � diagonal dominante. Tentando reorganizar para garantir converg�ncia..." << endl;
        reorganizarParaDominante(sistema, tamanho);
        if (!matrizDiagonalDominante(sistema, tamanho)) {
            cout << "Reorganiza��o falhou. O m�todo Gauss-Jacobi pode n�o convergir corretamente." << endl;
        } else {
            cout << "Matriz reorganizada com sucesso para garantir diagonal dominante." << endl;
        }
    }

    // Processo iterativo do m�todo de Gauss-Jacobi
    for (int iteracao = 0; iteracao < MAX_TENTATIVAS; iteracao++) {
        double erroAtual = 0;

        // Atualiza as vari�veis com base nas equa��es e na solu��o anterior
        for (int i = 0; i < tamanho; i++) {
            double soma = sistema[i][tamanho]; // Termo independente
            for (int j = 0; j < tamanho; j++) {
                if (i != j) {
                    soma -= sistema[i][j] * solucaoAnterior[j]; // Subtrai elementos das outras vari�veis
                }
            }
            resultado[i] = soma / sistema[i][i]; // Atualiza a solu��o para a vari�vel atual

            // Calcula o erro atual
            erroAtual += fabs(resultado[i] - solucaoAnterior[i]);
        }

        // Exibe o estado da itera��o atual
        cout << "Itera��o " << iteracao + 1 << ":" << endl;
        for (int i = 0; i < tamanho; i++) {
            cout << "x" << i + 1 << " = " << resultado[i] << " ";
        }
        cout << endl;
        cout << "Erro acumulado nesta itera��o: " << erroAtual << endl;
        cout << "------------------------------" << endl;

        // Atualiza o vetor da solu��o anterior
        for (int i = 0; i < tamanho; i++) {
            solucaoAnterior[i] = resultado[i];
        }

        // Verifica se o erro � menor que a toler�ncia, ou seja, se convergiu
        if (erroAtual <= ERRO_TOLERAVEL) {
            cout << "O m�todo Gauss-Jacobi convergiu ap�s " << iteracao + 1 << " itera��es." << endl;
            delete[] solucaoAnterior; // Libera a mem�ria alocada
            return;
        }
    }

    cout << "O m�todo n�o convergiu ap�s " << MAX_TENTATIVAS << " itera��es." << endl;
    delete[] solucaoAnterior; // Libera a mem�ria alocada
}

int main() {
    setlocale(LC_CTYPE, ""); // Configura a localidade para suportar acentua��o
    int tamanhoMatriz;

    // Solicita o tamanho da matriz ao usu�rio
    cout << "Digite o tamanho da matriz de coeficientes do sistema: ";
    cin >> tamanhoMatriz;

    // Aloca dinamicamente a matriz de coeficientes do sistema linear
    double** sistemaLinear = new double*[tamanhoMatriz];
    for (int i = 0; i < tamanhoMatriz; i++) {
        sistemaLinear[i] = new double[tamanhoMatriz + 1]; // Inclui a coluna dos termos independentes
    }

    // Solicita ao usu�rio que insira os coeficientes do sistema linear
    cout << "Insira os coeficientes da matriz e os termos independentes (linha por linha):" << endl;
    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz + 1; j++) {
            cin >> sistemaLinear[i][j];
        }
    }

    // Aloca o vetor para armazenar as solu��es
    double* solucaoSistema = new double[tamanhoMatriz];

    // Aplica o m�todo de Gauss-Jacobi para encontrar a solu��o do sistema
    resolverGaussJacobi(sistemaLinear, tamanhoMatriz, solucaoSistema);

    // Exibe as solu��es finais
    cout << "Solu��es finais do sistema:" << endl;
    for (int i = 0; i < tamanhoMatriz; i++) {
        cout << "x" << i + 1 << " = " << solucaoSistema[i] << endl;
    }

    // Libera a mem�ria alocada para a matriz e o vetor de solu��es
    for (int i = 0; i < tamanhoMatriz; i++) {
        delete[] sistemaLinear[i];
    }
    delete[] sistemaLinear;
    delete[] solucaoSistema;

    return 0;
}
