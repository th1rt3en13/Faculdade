//parimpar.cpp
#include "parimpar.h"

void impar (int *valor){
	for (int i=0; i<10; i++){
		if (valor[i]%2!=0){
			cout << valor[i] << " ";		
		}
	}
}

void par (int *valor){
	for (int i=0; i<10; i++){
		if (valor[i]%2==0){
			cout << valor[i] << " ";
		}
	}	
}

