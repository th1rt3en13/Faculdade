#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <stdlib.h>
#define TAM 70

using namespace std;

struct st_disciplina {
    char nome_disciplina[TAM];
    int creditos;
};
typedef struct st_disciplina disciplina;

struct st_aluno {
    char nome_completo[TAM];
    char email[TAM];
    int telefone;
};
typedef struct st_aluno aluno;

struct st_professor {
    char nome[TAM];
    char sobrenome[TAM];
    int telefone;
};
typedef struct st_professor professor;

struct st_turma {
    professor* professor_titular;
    disciplina* Disciplina;
    aluno* lista_alunos;
    int num_alunos;
};
typedef struct st_turma turma;

turma* cadastrar_turma(turma* t);
professor* cadastrar_professor();
disciplina* cadastrar_disciplina();
aluno* cadastrar_aluno(int num_alunos);
void imprimir_turma(turma* t);
void desalocar(turma* t);

#endif // FUNCOES_H

