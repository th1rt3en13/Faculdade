#include <stdio.h>

int main() {
    int vetor1[5] = {1, 2, 3, 4, 5};
    int vetor2[5] = {6, 7, 8, 9, 10};
    int vetor3[10];

    // Preenche as primeiras 5 posições de vetor3 com os valores de vetor1 e vetor2
    for (int i = 0; i < 5; i++) {
        vetor3[i] = vetor1[i];
        vetor3[i + 5] = vetor2[4 - i];
        printf ("%d\t %d\n", vetor1[i], vetor2[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor3[i]);
    }
    printf("\n");

    return 0;
}
