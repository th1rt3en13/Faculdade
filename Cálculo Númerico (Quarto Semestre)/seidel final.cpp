//seidel
#include <iostream>
#include <cmath>

using namespace std;

const int MAX_TENTATIVAS = 1000; // N�mero m�ximo de itera��es
const double ERRO_TOLERADO = 0.005; // Toler�ncia para o crit�rio de parada - erro

// Fun��o para verificar se a matriz tem diagonal dominante
bool matrizEhDiagonalDominante(double** sistema, int tamanho) {
    for (int linha = 0; linha < tamanho; linha++) {
        double somaNaoDiagonal = 0;
        for (int coluna = 0; coluna < tamanho; coluna++) {
            if (linha != coluna) {
                somaNaoDiagonal += fabs(sistema[linha][coluna]); // Soma dos elementos fora da diagonal
            }
        }
        if (fabs(sistema[linha][linha]) <= somaNaoDiagonal) {
            return false; // N�o � diagonal dominante
        }
    }
    return true; // � diagonal dominante
}

// Fun��o para trocar as linhas da matriz se necess�rio
void substituirLinhas(double** sistema, int tamanho, int linha1, int linha2) {
    for (int coluna = 0; coluna < tamanho + 1; coluna++) {
        swap(sistema[linha1][coluna], sistema[linha2][coluna]); // Troca as linhas
    }
}

// Fun��o para reorganizar a matriz para garantir que seja diagonal dominante
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

// Fun��o para aplicar o m�todo de Gauss-Seidel
void resolverGaussSeidel(double** sistema, int tamanho, double* solucao) {
    double* solucaoAnterior = new double[tamanho]; // Vetor para armazenar a solu��o anterior
    for (int i = 0; i < tamanho; i++) {
        solucaoAnterior[i] = 0; // Inicializa a solu��o com zeros
    }

    // Verifica se a matriz � diagonal dominante
    if (!matrizEhDiagonalDominante(sistema, tamanho)) {
        cout << "A matriz fornecida n�o � diagonal dominante. Tentando reorganizar..." << endl;
        ajustarParaDiagonalDominante(sistema, tamanho);
        if (!matrizEhDiagonalDominante(sistema, tamanho)) {
            cout << "N�o foi poss�vel reorganizar a matriz para ser diagonal dominante. O m�todo pode n�o convergir." << endl;
        } else {
            cout << "Matriz reorganizada com sucesso para ser diagonal dominante." << endl;
        }
    }

    // Processo iterativo do m�todo de Gauss-Seidel
    for (int iteracao = 0; iteracao < MAX_TENTATIVAS; iteracao++) {
        double erroAtual = 0;

        // Atualiza as vari�veis utilizando a solu��o atualizada imediatamente
        for (int linha = 0; linha < tamanho; linha++) {
            double soma = sistema[linha][tamanho]; // Termo independente
            for (int coluna = 0; coluna < tamanho; coluna++) {
                if (linha != coluna) {
                    soma -= sistema[linha][coluna] * solucao[coluna]; // Subtrai os valores calculados
                }
            }
            double novaSolucao = soma / sistema[linha][linha];
            erroAtual += fabs(novaSolucao - solucao[linha]);
            solucao[linha] = novaSolucao; // Atualiza a solu��o imediatamente
        }

        // Exibe o estado da itera��o atual
        cout << "Itera��o " << iteracao + 1 << ":" << endl;
        for (int i = 0; i < tamanho; i++) {
            cout << "x" << i + 1 << " = " << solucao[i] << " ";
        }
        cout << endl;
        cout << "Erro atual nesta itera��o: " << erroAtual << endl;
        cout << "------------------------------" << endl;

        // Verifica se o erro � menor que a toler�ncia, indicando converg�ncia
        if (erroAtual <= ERRO_TOLERADO) {
            cout << "M�todo convergiu ap�s " << iteracao + 1 << " itera��es." << endl;
            delete[] solucaoAnterior; // Libera a mem�ria alocada
            return;
        }
    }

    cout << "O m�todo n�o convergiu ap�s " << MAX_TENTATIVAS << " tentativas." << endl;
    delete[] solucaoAnterior; // Libera a mem�ria alocada
}

int main() {
    setlocale(LC_CTYPE, ""); // Configura a localidade para suportar acentua��o
    int tamanhoSistema;

    // Solicita o tamanho da matriz ao usu�rio
    cout << "Digite o tamanho do sistema de equa��es: ";
    cin >> tamanhoSistema;

    // Aloca dinamicamente a matriz do sistema linear
    double** sistemaLinear = new double*[tamanhoSistema];
    for (int i = 0; i < tamanhoSistema; i++) {
        sistemaLinear[i] = new double[tamanhoSistema + 1]; // Inclui os termos independentes
    }

    // Solicita ao usu�rio que insira os coeficientes do sistema linear
    cout << "Digite os coeficientes do sistema de equa��es (incluindo os termos independentes):" << endl;
    for (int i = 0; i < tamanhoSistema; i++) {
        for (int j = 0; j < tamanhoSistema + 1; j++) {
            cin >> sistemaLinear[i][j];
        }
    }

    // Aloca o vetor para armazenar as solu��es
    double* solucaoSistema = new double[tamanhoSistema];

    // Aplica o m�todo de Gauss-Seidel
    resolverGaussSeidel(sistemaLinear, tamanhoSistema, solucaoSistema);

    // Exibe as solu��es finais
    cout << "Solu��es finais: " << endl;
    for (int i = 0; i < tamanhoSistema; i++) {
        cout << "x" << i + 1 << " = " << solucaoSistema[i] << endl;
    }

    // Libera a mem�ria alocada
    for (int i = 0; i < tamanhoSistema; i++) {
        delete[] sistemaLinear[i];
    }
    delete[] sistemaLinear;
    delete[] solucaoSistema;

    return 0;
}
