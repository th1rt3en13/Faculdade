//funcoes.h
#include <stdlib.h>
using namespace std;

struct st_aluno{
	char* nome;
	float nota;
}; typedef struct st_aluno aluno;

aluno* cadastrar_aluno(int* cont, aluno* aux);
void alunos_cadastrados(int i,int  cont, aluno* aux);
void alunos_cadastrados_aprov (int i, int cont, aluno* aux);
void alunos_cadastrados_repr (int i, int cont, aluno* aux);
int quant_total (int i, int cont, aluno*aux);
int quant_aprov (int i, int cont, aluno* aux);
int quant_repr (int i, int cont, aluno* aux);
aluno* desalocar(int* cont, aluno* aux);
