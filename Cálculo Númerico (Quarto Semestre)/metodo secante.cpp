//metodo secante
#include <iostream>
#include <math.h>
using namespace std;

float f (float x){
	// f(x) = x^3 - 5
	return (pow(x,3))-5;
	
	//opcao 2
	// f(x) = x^2 - 4
	//return pow (x,2)-4;
}

void secante(float x0, float x1, int maxIter, double tol) {
	
    float x2; // Próxima aproximação da raiz

    for (int i = 0; i < maxIter; i++) {
        // Calcula o valor de x2 usando a fórmula da secante
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        // Verifica se a diferença eh menor que a tolerancia
        if (fabs(x2 - x1) < tol) {
        	cout<<endl;
            cout << "Raiz encontrada em x = " << x2 << " apos " << i + 1 << " iteracoes." << endl;
            return;
        }

        // Atualiza os valores para a proxima vez
        x0 = x1;
        x1 = x2;
    }

    cout << "Método falhou após " << maxIter << " iterações." << endl;
}

int main (){
	float a, b;
	int k;
	double tol;
	//a = x0
	//b= x1
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
	
	secante (a,b,k,tol);
	
	return 0;
}
