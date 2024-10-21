//regra_trapezio.cpp
#include <iostream>
using namespace std;

float f(float x){
	return 1/x;
}

void regra_trapezio (float a, float b, int n){
	
	if (a <= 0 || b <= 0) {
        cout << "Os limites devem ser maiores que zero." << endl;
        return;
    }

    float h = (b - a) / n;
    float tot = 0;  
    float x = a;

    cout << "i" << "      " << "x" << "      " << "f(x)" << "          " << "c" << "      " << "c*f(x)" << endl;
	
	for (int i=0; i<=n; i++){
		float fx= f(x);
		int c;
		if (i==0 || i==n){
			c=1;
		}else {
			c=2;
		}
		tot += c*fx;
		cout<< i<<"      "<<x<<"      "<<fx<<"        "<<c<<"      "<<c*fx<<endl;
		x += h;
	}
	
	cout<<endl;
	cout<<"resultado final = "<<(h/2)*tot;
	
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
	
	regra_trapezio (a,b,n);
	
	return 0;
}
