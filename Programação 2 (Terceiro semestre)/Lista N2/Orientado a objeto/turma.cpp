#include "Turma.h"
#include <iostream>
using namespace std;

void Turma::setProfessorTitular(const Professor &professor) {
    this->professorTitular = professor;
}

void Turma::setDisciplina(const Disciplina &disciplina) {
    this->disciplina = disciplina;
}

void Turma::addAluno(const Aluno &aluno) {
    this->listaAlunos.push_back(aluno);
}

Professor Turma::getProfessorTitular() const {
    return professorTitular;
}

Disciplina Turma::getDisciplina() const {
    return disciplina;
}

vector<Aluno> Turma::getListaAlunos() const {
    return listaAlunos;
}

void Turma::cadastrarTurma() {
    if (turmaCadastrada) {
        cout << "Ja existe uma turma cadastrada.\n";
        return;
    }

    cout << "CADASTRO DE TURMA\n\n";
    
    professorTitular.cadastrarProfessor();
    setProfessorTitular(professorTitular);
    
    disciplina.cadastrarDisciplina();
    setDisciplina(disciplina);
    
    int numAlunos;
    cout << "Informe o numero de alunos: ";
    cin >> numAlunos;

    for (int i = 0; i < numAlunos; ++i) {
        Aluno aluno;
        aluno.cadastrarAluno();
        addAluno(aluno);
    }

    turmaCadastrada = true; // Define que uma turma foi cadastrada
}

void Turma::imprimirTurma() const {
    if (!turmaCadastrada) {
        cout << "Nao ha nenhuma turma cadastrada.\n";
        return;
    }

    cout << "\n>Professor cadastrado na turma:\n";
    cout << "Nome do professor: " << professorTitular.getNome() << "\n";
    cout << "Sobrenome do professor: " << professorTitular.getSobrenome() << "\n";
    cout << "Telefone do professor: " << professorTitular.getTelefone() << "\n\n";
    
    cout << ">Disciplina cadastrada na turma:\n";
    cout << "Nome da disciplina: " << disciplina.getNomeDisciplina() << "\n";
    cout << "Créditos da disciplina: " << disciplina.getCreditos() << "\n\n";
    
    cout << ">Alunos cadastrados na turma:\n";
    for (size_t i = 0; i < listaAlunos.size(); ++i) {
        cout << "Aluno " << i + 1 << ": \n";
        cout << "Nome completo do aluno: " << listaAlunos[i].getNomeCompleto() << "\n";
        cout << "Email do aluno: " << listaAlunos[i].getEmail() << "\n";
        cout << "Telefone do aluno: " << listaAlunos[i].getTelefone() << "\n\n";
    }
}

void Turma::desalocar() {
    listaAlunos.clear();
    turmaCadastrada = false; // Define que não há uma turma cadastrada
}

bool Turma::isTurmaCadastrada() const {
    return turmaCadastrada;
}



