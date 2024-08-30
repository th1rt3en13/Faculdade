//metodo newton
#include <iostream>
#include <math.h>
using namespace std;

float f (float x){
	return pow (x,2)-4;
}

float f_der (float x){
	return 2*x;
}

//funcao = x^2-4
//derivada = 2x

float newton (float x, int n, double tol){
	
	//iteracao atual
	int k=1;
	float x_inicial = x;
	
	if (f_der(x)==0){
		cout<<"Metodo falhou, derivada igual a zero na aproximacao inicial"<<endl;
		return 0;
	}
	
	while (k<=n){
		
		x = x_inicial - (f(x_inicial)/f_der(x_inicial));
		
		if (fabs(x-x_inicial)<tol || fabs(x-x_inicial)/fabs(x)<tol || fabs(f(x))<tol){
			cout<< "Raiz: "<< x<< " apos "<<k<<" iteracoes"<<endl;
			return 0;
		}
		
		k++;
		x_inicial = x;
	}
	
	cout << "Metodo falhou apos " << n << " iteracoes" << endl;
}

int main(){
	float x;
	int n;
	double tol;
	//x = aproximacao inicial
	//n = numero max de iteracoes
	//tol = tolerancia
	
	cout<< "Digite o valor de X (aproximacao inicial): "<<endl;
	cin>> x;
	cout<< "Digite o numero maximo de iteracoes: "<<endl;
	cin>>n;
	cout<< "Digite o valor da tolerancia: "<<endl;
	cin>> tol;
	
	//funcao = x^2-4
	
	newton (x, n , tol);
	
	return 0;
}
