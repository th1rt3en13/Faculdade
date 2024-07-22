#include <stdio.h>

int main() {
    float saldoMedio, valorCredito;

    printf("Digite o saldo médio do cliente: ");
    scanf("%f", &saldoMedio);

    if (saldoMedio >= 0 && saldoMedio <= 500) {
        valorCredito = 0;
    } else if (saldoMedio <= 1000) {
        valorCredito = saldoMedio * 0.3;
    } else if (saldoMedio <= 3000) {
        valorCredito = saldoMedio * 0.4;
    } else {
        valorCredito = saldoMedio * 0.5;
    }

    printf("Saldo médio: %.2f\n", saldoMedio);
    printf("Valor de crédito: %.2f\n", valorCredito);
}