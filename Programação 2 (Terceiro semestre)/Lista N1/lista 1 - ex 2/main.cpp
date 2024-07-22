#include <iostream>
#include "dobrotriploqua.h"
using namespace std;

int obter_num(){
	int a;
	cout << "Digite A: ";
    cin >> a;
    return a;
}

int main() {
	//obtendo numero
    int a = obter_num();
    
    //declarando e atribuindo os respectivos enderecos de memoria
    int *b =&a;
    int **c = &b;
    int ***d = &c;
    
    //declarando e chamando as funcoes
    int dobro = calcular_dobro(b);
    int triplo = calcular_triplo(c);
    int quadruplo = calcular_quadruplo(d);
    
	//imprimindo o dobro, triplo e quadruplo
    cout << "Valor de B (dobro): " << dobro << endl;
	cout << "Valor de C (triplo): " << triplo << endl;
	cout << "Valor de D (quadruplo): " << quadruplo << endl;
	
    return 0;
};
