//regra_retangulo.cpp
#include <iostream>

using namespace std;


float f(float x){
	return x/(1+(x*x));
}

void regra_retangulo(float a, float b, int n){
	
	float h = (b-a)/n;
	float soma = 0;
	float x = a;
	
	cout<< "h = "<<h<<endl;
	cout<<endl;
	
	cout << "i" << "      " << "xi" << "        " << "f(x)" << endl;
	
	for (int i=0; i<n; i++){
		float x_i = a + i * h;  
        float x_medio = x_i + h / 2;  
        float valor_f = f(x_medio);  
        soma += valor_f;  
        cout << i << "      " << x_medio << "      " << valor_f << endl;
    }

    cout << endl;
    cout << "Resultado final = " << soma * h << endl; 
}


int main(){
	float a,b;
	int n;
	
	cout<<"digite o valor de a: "<<endl;
	cin>>a;
	cout<<"digite o valor de b: "<<endl;
	cin>>b;
	cout<<"digite o valor de n: "<<endl;
	cin>>n;
	cout<<endl;
	
	regra_retangulo (a,b,n);
	
	return 0;
}
