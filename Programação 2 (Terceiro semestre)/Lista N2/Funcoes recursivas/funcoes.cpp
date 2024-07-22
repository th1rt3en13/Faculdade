//funcoes.cpp
#include "funcoes.h"
#include <iostream>
#define tam 15
using namespace std;

aluno* cadastrar_aluno(int* cont, aluno* aux){
	//*cont++; //cuidado, isto faz primeiro cont++ para depois usar apontamento *, ou seja, incrementa o endereço de memória em cont fazendo apontar para endereço errado, perdendo a referência original
	(*cont)++; //*cont = *cont + 1; //equivalentes
	if (*cont == 1){
		//primeira alocacao
		aux = (aluno*)malloc(sizeof(aluno));
	} else {
		//mais de uma alocacao...
		aux = (aluno*)realloc(aux, *cont * sizeof(aluno)); 
	}
	//cadastrar dados na memoria recem-alocada
	aux[*cont-1].nome = (char*) malloc(sizeof(char)*tam);
	cout << "Informe nome do aluno: ";
	fflush(stdin); //limpa buffer  teclado antes de leitura de dados, evitando quebra da leitura do menu em caso de lixo 
	cin.getline(aux[*cont-1].nome, tam);
	cout << "Informe nota: ";
	fflush(stdin);
	cin >> aux[*cont-1].nota;
	cout << endl;
	return aux;
}
void alunos_cadastrados(int i, int cont, aluno* aux){
	if (i >= cont) {
        return;
    }
	cout << "Nome: " << aux[i].nome << endl;
    cout << "Nota: " << aux[i].nota << endl;
    cout<<endl;
    alunos_cadastrados(i+1,cont, aux);
}

void alunos_cadastrados_aprov (int i, int cont, aluno* aux){
	if (i>=cont){
		return;
	}
	if (aux[i].nota>=7){
		cout << "Nome: " << aux[i].nome << endl;
    	cout << "Nota: " << aux[i].nota << endl;
    	cout<<endl;
	}
	alunos_cadastrados_aprov(i+1,cont, aux);
}

void alunos_cadastrados_repr (int i, int cont, aluno* aux){
	if (i>=cont){
		return;
	}
	if (aux[i].nota<7){
		cout << "Nome: " << aux[i].nome << endl;
    	cout << "Nota: " << aux[i].nota << endl;
    	cout<<endl;
	}
	alunos_cadastrados_repr(i+1,cont, aux);
}

int quant_total (int i, int cont, aluno*aux){
	if (i>=cont){
		return 0 ;
	}
	return 1 + quant_total(i+1, cont, aux);
}

int quant_aprov (int i, int cont, aluno* aux){
	if (i>=cont){
		return 0 ;
	}
	if (aux[i].nota>=7){
		return 1 + quant_aprov(i+1, cont, aux);	
	}
	return quant_aprov(i+1, cont, aux);
}

int quant_repr (int i, int cont, aluno* aux){
	if (i>=cont){
		return 0 ;
	}
	if (aux[i].nota<7){
		return 1 + quant_repr(i+1, cont, aux);	
	}
	return quant_repr(i+1, cont, aux);
}

aluno* desalocar(int* cont, aluno* aux){
	*cont = 0;
	free(aux); 
	return NULL; 
}

