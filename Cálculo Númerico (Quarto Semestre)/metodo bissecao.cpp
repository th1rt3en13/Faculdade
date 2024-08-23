//metodo da bissecao
#include <iostream>
#include <math.h>
using namespace std;

float f(float x){
	return (pow(x,3))-5;
}

float bissecao (float a, float b, double tol, int k){
	//funcao = x^3-5
	float p;
	
	if (f(a)*f(b)>0){
		cout <<"Metodo falho"<<endl;
		return 0;
	}
	
	for (int i=0; i<k; i++){
        
        p = (a + b) / 2;
        
		if (((b-a)/2<tol) || (fabs(f(p)) < tol)){
			cout <<"A raiz "<<p<<" atingiu a tolerancia"<<endl;
			return 0;
		} 
		if (f(a) * f(p)>0){
			a = p;
		} else {
			b = p;
		}
	}
	cout <<"A raiz tem o valor aproximado de "<<p<<endl;
}

int main(){
	float a, b;
	int k;
	double tol;
	//a = esquerda do intervalo
	//b= direita do intervalo
	//k = numero max de iteracoes
	//tol = tolerancia
	
	cout<< "Digite o valor de A: "<<endl;
	cin>> a;
	cout<< "Digite o valor de B: "<<endl;
	cin>> b;
	cout<< "Digite o numero maximo de iteracoes: "<<endl;
	cin>>k;
	cout<< "Digite o valor da tolerancia: "<<endl;
	cin>> tol;
	
	//funcao = x^3+5
	
	bissecao (a,b,tol,k);
	
	return 0;
}
