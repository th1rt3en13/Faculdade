#include <iostream>
#include <cmath>

using namespace std;

const int MAX_TENTATIVAS = 1000; // Número máximo de iterações
const double ERRO_TOLERAVEL = 0.0001; // Tolerância para o critério de parada - erro

// Função para verificar se a matriz tem diagonal dominante
bool matrizDiagonalDominante(double** sistema, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        double soma_linha = 0;
        for (int j = 0; j < tamanho; j++) {
            if (i != j) {
                soma_linha += fabs(sistema[i][j]); // Soma dos elementos fora da diagonal
            }
        }
        if (fabs(sistema[i][i]) <= soma_linha) {
            return false; // Não é diagonal dominante
        }
    }
    return true; // É diagonal dominante
}

// Função para trocar as linhas da matriz quando necessário
void alterarLinhas(double** sistema, int tamanho, int linha1, int linha2) {
    for (int i = 0; i < tamanho + 1; i++) {
        swap(sistema[linha1][i], sistema[linha2][i]); // Troca elementos entre as linhas
    }
}

// Função para reorganizar a matriz para garantir diagonal dominante
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

// Função para aplicar o método de Gauss-Jacobi
void resolverGaussJacobi(double** sistema, int tamanho, double* resultado) {
    double* solucaoAnterior = new double[tamanho]; // Vetor para armazenar a solução anterior
    for (int i = 0; i < tamanho; i++) {
        solucaoAnterior[i] = 0; // Inicializa com zero
    }

    // Verifica se a matriz é diagonal dominante
    if (!matrizDiagonalDominante(sistema, tamanho)) {
        cout << "A matriz não é diagonal dominante. Tentando reorganizar para garantir convergência..." << endl;
        reorganizarParaDominante(sistema, tamanho);
        if (!matrizDiagonalDominante(sistema, tamanho)) {
            cout << "Reorganização falhou. O método Gauss-Jacobi pode não convergir corretamente." << endl;
        } else {
            cout << "Matriz reorganizada com sucesso para garantir diagonal dominante." << endl;
        }
    }

    // Processo iterativo do método de Gauss-Jacobi
    for (int iteracao = 0; iteracao < MAX_TENTATIVAS; iteracao++) {
        double erroAtual = 0;

        // Atualiza as variáveis com base nas equações e na solução anterior
        for (int i = 0; i < tamanho; i++) {
            double soma = sistema[i][tamanho]; // Termo independente
            for (int j = 0; j < tamanho; j++) {
                if (i != j) {
                    soma -= sistema[i][j] * solucaoAnterior[j]; // Subtrai elementos das outras variáveis
                }
            }
            resultado[i] = soma / sistema[i][i]; // Atualiza a solução para a variável atual

            // Calcula o erro atual
            erroAtual += fabs(resultado[i] - solucaoAnterior[i]);
        }

        // Exibe o estado da iteração atual
        cout << "Iteração " << iteracao + 1 << ":" << endl;
        for (int i = 0; i < tamanho; i++) {
            cout << "x" << i + 1 << " = " << resultado[i] << " ";
        }
        cout << endl;
        cout << "Erro acumulado nesta iteração: " << erroAtual << endl;
        cout << "------------------------------" << endl;

        // Atualiza o vetor da solução anterior
        for (int i = 0; i < tamanho; i++) {
            solucaoAnterior[i] = resultado[i];
        }

        // Verifica se o erro é menor que a tolerância, ou seja, se convergiu
        if (erroAtual <= ERRO_TOLERAVEL) {
            cout << "O método Gauss-Jacobi convergiu após " << iteracao + 1 << " iterações." << endl;
            delete[] solucaoAnterior; // Libera a memória alocada
            return;
        }
    }

    cout << "O método não convergiu após " << MAX_TENTATIVAS << " iterações." << endl;
    delete[] solucaoAnterior; // Libera a memória alocada
}

int main() {
    setlocale(LC_CTYPE, ""); // Configura a localidade para suportar acentuação
    int tamanhoMatriz;

    // Solicita o tamanho da matriz ao usuário
    cout << "Digite o tamanho da matriz de coeficientes do sistema: ";
    cin >> tamanhoMatriz;

    // Aloca dinamicamente a matriz de coeficientes do sistema linear
    double** sistemaLinear = new double*[tamanhoMatriz];
    for (int i = 0; i < tamanhoMatriz; i++) {
        sistemaLinear[i] = new double[tamanhoMatriz + 1]; // Inclui a coluna dos termos independentes
    }

    // Solicita ao usuário que insira os coeficientes do sistema linear
    cout << "Insira os coeficientes da matriz e os termos independentes (linha por linha):" << endl;
    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz + 1; j++) {
            cin >> sistemaLinear[i][j];
        }
    }

    // Aloca o vetor para armazenar as soluções
    double* solucaoSistema = new double[tamanhoMatriz];

    // Aplica o método de Gauss-Jacobi para encontrar a solução do sistema
    resolverGaussJacobi(sistemaLinear, tamanhoMatriz, solucaoSistema);

    // Exibe as soluções finais
    cout << "Soluções finais do sistema:" << endl;
    for (int i = 0; i < tamanhoMatriz; i++) {
        cout << "x" << i + 1 << " = " << solucaoSistema[i] << endl;
    }

    // Libera a memória alocada para a matriz e o vetor de soluções
    for (int i = 0; i < tamanhoMatriz; i++) {
        delete[] sistemaLinear[i];
    }
    delete[] sistemaLinear;
    delete[] solucaoSistema;

    return 0;
}
