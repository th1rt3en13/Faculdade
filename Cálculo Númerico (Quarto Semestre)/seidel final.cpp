//seidel
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_TENTATIVAS = 1000; // Número máximo de iterações
const double ERRO_TOLERADO = 0.005; // Tolerância para o critério de parada - erro

// Função para verificar se a matriz tem diagonal dominante
bool matrizEhDiagonalDominante(double** sistema, int tamanho) {
    for (int linha = 0; linha < tamanho; linha++) {
        double somaNaoDiagonal = 0;
        for (int coluna = 0; coluna < tamanho; coluna++) {
            if (linha != coluna) {
                somaNaoDiagonal += fabs(sistema[linha][coluna]); // Soma dos elementos fora da diagonal
            }
        }
        if (fabs(sistema[linha][linha]) <= somaNaoDiagonal) {
            return false; // Não é diagonal dominante
        }
    }
    return true; // É diagonal dominante
}

// Função para trocar as linhas da matriz se necessário
void substituirLinhas(double** sistema, int tamanho, int linha1, int linha2) {
    for (int coluna = 0; coluna < tamanho + 1; coluna++) {
        swap(sistema[linha1][coluna], sistema[linha2][coluna]); // Troca as linhas
    }
}

// Função para reorganizar a matriz para garantir que seja diagonal dominante
void ajustarParaDiagonalDominante(double** sistema, int tamanho) {
    for (int linha = 0; linha < tamanho; linha++) {
        if (fabs(sistema[linha][linha]) < fabs(sistema[linha][(linha + 1) % tamanho]) || 
            fabs(sistema[linha][linha]) < fabs(sistema[linha][(linha + 2) % tamanho])) {
            substituirLinhas(sistema, tamanho, linha, (linha + 1) % tamanho); // Tenta trocar linhas
        }
    }
}

//exemplo
//4 -1 0 7
//-1 3 -1 6
//0 -1 4 5

// Função para aplicar o método de Gauss-Seidel
void resolverGaussSeidel(double** sistema, int tamanho, double* solucao) {
    double* solucaoAnterior = new double[tamanho]; // Vetor para armazenar a solução anterior
    for (int i = 0; i < tamanho; i++) {
        solucaoAnterior[i] = 0; // Inicializa a solução com zeros
    }

    // Verifica se a matriz é diagonal dominante
    if (!matrizEhDiagonalDominante(sistema, tamanho)) {
        cout << "A matriz fornecida não é diagonal dominante. Tentando reorganizar..." << endl;
        ajustarParaDiagonalDominante(sistema, tamanho);
        if (!matrizEhDiagonalDominante(sistema, tamanho)) {
            cout << "Não foi possível reorganizar a matriz para ser diagonal dominante. O método pode não convergir." << endl;
        } else {
            cout << "Matriz reorganizada com sucesso para ser diagonal dominante." << endl;
        }
    }

    // Processo iterativo do método de Gauss-Seidel
    for (int iteracao = 0; iteracao < MAX_TENTATIVAS; iteracao++) {
        double erroAtual = 0;

        // Atualiza as variáveis utilizando a solução atualizada imediatamente
        for (int linha = 0; linha < tamanho; linha++) {
            double soma = sistema[linha][tamanho]; // Termo independente
            for (int coluna = 0; coluna < tamanho; coluna++) {
                if (linha != coluna) {
                    soma -= sistema[linha][coluna] * solucao[coluna]; // Subtrai os valores calculados
                }
            }
            double novaSolucao = soma / sistema[linha][linha];
            erroAtual += fabs(novaSolucao - solucao[linha]);
            solucao[linha] = novaSolucao; // Atualiza a solução imediatamente
        }

        // Exibe o estado da iteração atual
        cout << "Iteração " << iteracao + 1 << ":" << endl;
        for (int i = 0; i < tamanho; i++) {
            cout << "x" << i + 1 << " = " << solucao[i] << " ";
        }
        cout << endl;
        cout << "Erro atual nesta iteração: " << erroAtual << endl;
        cout << "------------------------------" << endl;

        // Verifica se o erro é menor que a tolerância, indicando convergência
        if (erroAtual <= ERRO_TOLERADO) {
            cout << "Método convergiu após " << iteracao + 1 << " iterações." << endl;
            delete[] solucaoAnterior; // Libera a memória alocada
            return;
        }
    }

    cout << "O método não convergiu após " << MAX_TENTATIVAS << " tentativas." << endl;
    delete[] solucaoAnterior; // Libera a memória alocada
}

int main() {
    setlocale(LC_CTYPE, ""); // Configura a localidade para suportar acentuação
    int tamanhoSistema;

    // Solicita o tamanho da matriz ao usuário
    cout << "Digite o tamanho do sistema de equações: ";
    cin >> tamanhoSistema;

    // Aloca dinamicamente a matriz do sistema linear
    double** sistemaLinear = new double*[tamanhoSistema];
    for (int i = 0; i < tamanhoSistema; i++) {
        sistemaLinear[i] = new double[tamanhoSistema + 1]; // Inclui os termos independentes
    }

    // Solicita ao usuário que insira os coeficientes do sistema linear
    cout << "Digite os coeficientes do sistema de equações (incluindo os termos independentes):" << endl;
    for (int i = 0; i < tamanhoSistema; i++) {
        for (int j = 0; j < tamanhoSistema + 1; j++) {
            cin >> sistemaLinear[i][j];
        }
    }

    // Aloca o vetor para armazenar as soluções
    double* solucaoSistema = new double[tamanhoSistema];

    // Aplica o método de Gauss-Seidel
    resolverGaussSeidel(sistemaLinear, tamanhoSistema, solucaoSistema);

    // Exibe as soluções finais
    cout << "Soluções finais: " << endl;
    for (int i = 0; i < tamanhoSistema; i++) {
        cout << "x" << i + 1 << " = " << solucaoSistema[i] << endl;
    }

    // Libera a memória alocada
    for (int i = 0; i < tamanhoSistema; i++) {
        delete[] sistemaLinear[i];
    }
    delete[] sistemaLinear;
    delete[] solucaoSistema;

    return 0;
}
