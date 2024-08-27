// teste_num.cpp
#include "teste_num.h"

bool eh_par(int num){
    return num % 2 == 0;
}

bool eh_impar(int num){
    return num % 2 != 0;
}

bool eh_primo(int num){
    if (num <= 1) return false; // N�meros menores ou iguais a 1 n�o s�o primos
    for (int i = 2; i <= num / 2; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

