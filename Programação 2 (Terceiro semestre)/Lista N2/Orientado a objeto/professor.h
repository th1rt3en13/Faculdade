#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
using namespace std;

class Professor {
private:
    string nome;
    string sobrenome;
    int telefone;

public:
    void setNome(const string &nome);
    void setSobrenome(const string &sobrenome);
    void setTelefone(int telefone);

    string getNome() const;
    string getSobrenome() const;
    int getTelefone() const;

    void cadastrarProfessor();
};

#endif // PROFESSOR_H


