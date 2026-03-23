#include <iostream>
#include <ctime>
#include "Ordenacao.h"

using namespace std;

int main() {
    int tamanho;
    char mostrar;

    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    Ordenacao obj(tamanho);
    obj.gerarAleatorio();

    cout << "Deseja mostrar os vetores ordenados? (s/n): ";
    cin >> mostrar;

    int *original = obj.getVetor();

    int *v1 = new int[tamanho];
    int *v2 = new int[tamanho];
    int *v3 = new int[tamanho];

    clock_t inicio, fim;

    // ---------------- Bubble Sort ----------------
    obj.copiarVetor(original, v1);

    inicio = clock();
    obj.bubbleSort(v1);
    fim = clock();

    double tempoBubble = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;

    // ---------------- Selection Sort ----------------
    obj.copiarVetor(original, v2);

    inicio = clock();
    obj.selectionSort(v2);
    fim = clock();

    double tempoSelection = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;

    // ---------------- Insertion Sort ----------------
    obj.copiarVetor(original, v3);

    inicio = clock();
    obj.insertionSort(v3);
    fim = clock();

    double tempoInsertion = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;

    // ---------------- Resultados ----------------
    cout << "\nTEMPOS (milissegundos):\n";
    cout << "Bubble Sort: " << tempoBubble << endl;
    cout << "Selection Sort: " << tempoSelection << endl;
    cout << "Insertion Sort: " << tempoInsertion << endl;

    if (mostrar == 's' || mostrar == 'S') {
        cout << "\nBubble Sort:\n";
        obj.imprimir(v1);

        cout << "\nSelection Sort:\n";
        obj.imprimir(v2);

        cout << "\nInsertion Sort:\n";
        obj.imprimir(v3);
    }

    delete[] v1;
    delete[] v2;
    delete[] v3;

    return 0;
}
