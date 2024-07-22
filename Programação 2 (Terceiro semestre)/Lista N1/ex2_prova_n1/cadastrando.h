//cadastrando.h
#include <iostream>
#include <stdlib.h>
using namespace std;


//montando struct e typedef: 'apelidando'
struct aluno{
	char* nome;
	int idade;
	int serie;
};
typedef struct aluno Aluno; 

Aluno* cadastrar_aluno();
void exibir_aluno(Aluno* aluno);
