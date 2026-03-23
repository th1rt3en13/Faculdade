#include "Ordenacao.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Ordenacao::Ordenacao(int tamanho) {
    this->tamanho = tamanho;
    vetor = new int[tamanho];
}

Ordenacao::~Ordenacao() {
    delete[] vetor;
}

void Ordenacao::gerarAleatorio() {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;
    }
}

int* Ordenacao::getVetor() {
    return vetor;
}

int Ordenacao::getTamanho() {
    return tamanho;
}

void Ordenacao::copiarVetor(int origem[], int destino[]) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

void Ordenacao::bubbleSort(int v[]) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void Ordenacao::selectionSort(int v[]) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }
}

void Ordenacao::insertionSort(int v[]) {
    for (int i = 1; i < tamanho; i++) {
        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void Ordenacao::imprimir(int v[]) {
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
