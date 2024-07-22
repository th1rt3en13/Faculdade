// funcoes.h
#include <iostream>
#include <stdlib.h>
using namespace std;

struct aluno {
    char* nome;
    int idade;
    int serie;
};
typedef struct aluno Aluno;

Aluno* cadastrar_aluno();
void exibir_aluno(Aluno* aluno);
void salvar_em_arquivo(Aluno* aluno, const char* filename);
Aluno* carregar_de_arquivo(const char* filename);
void desalocar_aluno(Aluno* aluno);
