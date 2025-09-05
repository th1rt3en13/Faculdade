//Calculadora_OO.cpp
//Objetiva implementar os métodos de classe prototipados no .h
#include "Calculadora_OO.h"
#include <cmath>

Calculadora_OO::Calculadora_OO(){
	this->n1 = this->n2 = 0;
}

Calculadora_OO::Calculadora_OO(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
}

Calculadora_OO::~Calculadora_OO(){
	//comandos úteis ao destrutor, se necessário, para desalocar recursos...
}

float Calculadora_OO::soma(){
	return this->n1 + this->n2;
}

float Calculadora_OO::soma(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->soma();
	//return Calculadora_OO::soma();
}

float Calculadora_OO::subtracao(){
	return this->n1 - this->n2;
}

float Calculadora_OO::subtracao(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->subtracao();
	//return Calculadora_OO::subtracao();
}

float Calculadora_OO::multiplicacao(){
	return this->n1 * this->n2;
}

float Calculadora_OO::multiplicacao(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->multiplicacao();
	//return Calculadora_OO::multiplicacao();
}

float Calculadora_OO::divisao(){
	return this->n1 / this->n2;
}

float Calculadora_OO::divisao(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->divisao();
	//return Calculadora_OO::divisao();
}

float Calculadora_OO::raiz(){
	// nn1: radicando
    // nn2: indice da raiz
    // formula x^(1/n)
    return pow(this->n1, 1.0 / this->n2);
}

float Calculadora_OO::raiz(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->raiz();
}

float Calculadora_OO::potencia(){
	// nn1: n
    // nn2: x
    // formula n^x
    return pow(this->n1,this->n2);
}

float Calculadora_OO::potencia(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->potencia();
}

int Calculadora_OO::par() {
    int num = static_cast<int>(this->n1);
    return (num % 2 == 0) ? 1 : 0;
}

int Calculadora_OO::par(float nn1) {
    this->n1 = nn1;
    return this->par();
}

int Calculadora_OO::impar() {
    int num = static_cast<int>(this->n1);
    return (num % 2 != 0) ? 1 : 0;
}

int Calculadora_OO::impar(float nn1) {
    this->n1 = nn1;
    return this->impar();
}

int Calculadora_OO::primo() {
    int num = static_cast<int>(this->n1);
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int Calculadora_OO::primo(float nn1) {
    this->n1 = nn1;
    return this->primo();
}
