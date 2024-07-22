#include "Professor.h"
#include <iostream>
using namespace std;

void Professor::setNome(const string &nome) {
    this->nome = nome;
}

void Professor::setSobrenome(const string &sobrenome) {
    this->sobrenome = sobrenome;
}

void Professor::setTelefone(int telefone) {
    this->telefone = telefone;
}

string Professor::getNome() const {
    return nome;
}

string Professor::getSobrenome() const {
    return sobrenome;
}

int Professor::getTelefone() const {
    return telefone;
}

void Professor::cadastrarProfessor() {
    cout << "Cadastrando dados do professor \n";
    string nome, sobrenome;
    int telefone;

    cout << "Informe nome do professor: ";
    cin >> nome;
    setNome(nome);

    cout << "Informe sobrenome do professor: ";
    cin >> sobrenome;
    setSobrenome(sobrenome);

    cout << "Informe telefone do professor: ";
    cin >> telefone;
    setTelefone(telefone);
    cout << endl;
}


