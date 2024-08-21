#include <iostream>
#include <math.h>
using namespace std;

int main() {
  float a, b, c, delta, x1, x2, x;

  //pegando valores
  cout<< "Entre com valor de A: ";
  cin>> a;
  cout<< "Entre com valor de B: ";
  cin>> b;
  cout<< "Entre com valor de C: ";
  cin>> c;

  //conferindo a
  while (a==0){
    cout<< "Nao eh uma equação do segundo grau, forneca um novo A: ";
    cin>>a;
  }

  //calculando delta
  delta = pow(b,2)-4*a*c;

  if (delta> 0){
    //duas raizes reais
    x1 = (-b + sqrt(delta))/(2*a);
    x2 = (-b - sqrt(delta))/(2*a);
    cout<< "As raizes sao: "<< x1 << " e "<< x2;
  }
  else if (delta<0){
    cout<<"Nao tem raiz real";
  }
  else{
    //uma raiz real
    x = -b/(2*a);
    cout<< "A raiz eh: "<< x;
  }
  return 0;
}
