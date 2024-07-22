#ifndef ALUNO_H
#define ALUNO_H

#include <string>
using namespace std;

class Aluno {
private:
    string nomeCompleto;
    string email;
    int telefone;

public:
    void setNomeCompleto(const string &nome);
    void setEmail(const string &email);
    void setTelefone(int telefone);

    string getNomeCompleto() const;
    string getEmail() const;
    int getTelefone() const;

    void cadastrarAluno();
};

#endif // ALUNO_H


