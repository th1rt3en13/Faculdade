#ifndef TURMA_H
#define TURMA_H

#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"
#include <vector>
using namespace std;

class Turma {
private:
    Professor professorTitular;
    Disciplina disciplina;
    vector<Aluno> listaAlunos;
    bool turmaCadastrada;

public:
    Turma() : turmaCadastrada(false) {} // Inicializa turmaCadastrada como false
    
    void setProfessorTitular(const Professor &professor);
    void setDisciplina(const Disciplina &disciplina);
    void addAluno(const Aluno &aluno);

    Professor getProfessorTitular() const;
    Disciplina getDisciplina() const;
    vector<Aluno> getListaAlunos() const;

    void cadastrarTurma();
    void imprimirTurma() const;
    void desalocar();
    bool isTurmaCadastrada() const; // Verifica se há uma turma cadastrada
};

#endif // TURMA_H


