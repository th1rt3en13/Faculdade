#include "Disciplina.h"
#include <iostream>
using namespace std;

void Disciplina::setNomeDisciplina(const string &nome) {
    this->nomeDisciplina = nome;
}

void Disciplina::setCreditos(int creditos) {
    this->creditos = creditos;
}

string Disciplina::getNomeDisciplina() const {
    return nomeDisciplina;
}

int Disciplina::getCreditos() const {
    return creditos;
}

void Disciplina::cadastrarDisciplina() {
    cout << "Cadastrando dados da disciplina \n";
    string nome;
    int creditos;

    cout << "Informe nome da disciplina: ";
    cin >> nome;
    setNomeDisciplina(nome);

    cout << "Informe os creditos da disciplina: ";
    cin >> creditos;
    setCreditos(creditos);
    cout << endl;
}

