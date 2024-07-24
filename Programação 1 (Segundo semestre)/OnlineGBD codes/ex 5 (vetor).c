#include <stdio.h>

int main() {
    int vetor1[5] = {1, 2, 3, 4, 5};
    int vetor2[5] = {6, 7, 8, 9, 10};
    int vetor3[10];

    for (int i = 0; i < 5; i++) {
        vetor3[i * 2] = vetor1[i]; // Preenche nas posições pares
        vetor3[i * 2 + 1] = vetor2[i]; // Preenche nas posições ímpares
        printf ("%d\t %d\n", vetor1[i], vetor2[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor3[i]);
    }
    printf("\n");

    return 0;
}

