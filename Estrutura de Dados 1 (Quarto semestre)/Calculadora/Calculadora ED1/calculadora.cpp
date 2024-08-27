//calculadora.cpp
#include "calculadora.h"

float soma (float num1, float num2){
	return (num1+num2);
}

float subtracao (float num1, float num2){
	return (num1-num2);
}

float multiplicacao (float num1, float num2){
	return (num1*num2);
}

float divisao (float num1, float num2){
	return (num1/num2);
}

float potencia (float num1, float num2){
	return pow(num1,num2);
}

float raiz (float num1, float num2){
	return pow(num1, 1.0/num2);
}
