#include "Aluno.h"
#include <iostream>
using namespace std;

void Aluno::setNomeCompleto(const string &nome) {
    this->nomeCompleto = nome;
}

void Aluno::setEmail(const string &email) {
    this->email = email;
}

void Aluno::setTelefone(int telefone) {
    this->telefone = telefone;
}

string Aluno::getNomeCompleto() const {
    return nomeCompleto;
}

string Aluno::getEmail() const {
    return email;
}

int Aluno::getTelefone() const {
    return telefone;
}

void Aluno::cadastrarAluno() {
    cout << "Cadastrando dados do aluno\n";
    string nome, email;
    int telefone;

    cout << "Nome completo do aluno: ";
    cin >> nome;
    setNomeCompleto(nome);

    cout << "Email do aluno: ";
    cin >> email;
    setEmail(email);

    cout << "Telefone do aluno: ";
    cin >> telefone;
    setTelefone(telefone);
    cout << endl;
}

