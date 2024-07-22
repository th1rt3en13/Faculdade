//parte_inteiro.cpp
#include "parte_inteiro.h"

void decomp_fracao(float* num, int* inteiro, float* frac) {
	*inteiro = static_cast<int>(*num);
    *frac = *num - *inteiro; 
}
