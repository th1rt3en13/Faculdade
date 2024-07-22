#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
using namespace std;

class Disciplina {
private:
    string nomeDisciplina;
    int creditos;

public:
    void setNomeDisciplina(const string &nome);
    void setCreditos(int creditos);

    string getNomeDisciplina() const;
    int getCreditos() const;

    void cadastrarDisciplina();
};

#endif // DISCIPLINA_H


