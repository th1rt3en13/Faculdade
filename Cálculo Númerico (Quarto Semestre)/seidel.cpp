//metodo seidel final
#include <iostream>
using namespace std;

#define linhas 3
#define colunas 3

void seidel(double A[linhas][colunas], double B[linhas], double chute[linhas], int n){
	
	for (int k=0; k<n;k++){
		
		for (int i=0; i<linhas; i++){
			
			double bi = B[i];
			
			for (int j=0; j<linhas; j++){ //percorrer todas as variaveis em uma linha. So vou mandar para o outro lado 
										  //se o numero da equacao for diferente da variavel
				if (j != i){
					
					bi -= A[i][j] * chute[j];  //isolando as variaveis
					
				}
			}
			bi /= A[i][i];
			cout<< "X"<<i+1<<" na iteracao "<<k+1<<" = "<<bi<<endl;
			chute[i] = bi;
		}
		
		cout<<endl;
		
	}
}

int main(){
	//declarando matriz
 double A[linhas][colunas] = {{4, 1, -1}, {-1, 3, 1}, {1, -1, 5}};
	double B[linhas] = {5, 6, 4};
	
	double chute[linhas]={-1,-1,-1};
	int n = 10; //iteracoes
	
	seidel(A, B, chute, n);

	return 0;
}
