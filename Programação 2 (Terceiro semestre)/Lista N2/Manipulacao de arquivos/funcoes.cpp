// funcoes.cpp
#include "funcoes.h"
#include <fstream>
#define tam 100  // Tamanho suficiente para o nome do aluno

Aluno* cadastrar_aluno() {
    Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
    novo_aluno->nome = new char[tam];
    
    cout << "Informe nome do aluno: ";
    cin.ignore();  // Limpar o buffer do teclado
    cin.getline(novo_aluno->nome, tam);

    cout << "Informe idade: ";
    cin >> novo_aluno->idade;

    cout << "Informe serie: ";
    cin >> novo_aluno->serie;

    return novo_aluno;
}

void exibir_aluno(Aluno* aluno) {
    cout << "Aluno cadastrado:\n";
    cout << "Nome: " << aluno->nome << endl;
    cout << "Idade: " << aluno->idade << endl;
    cout << "Serie: " << aluno->serie << endl;
}

void salvar_em_arquivo(Aluno* aluno, const char* filename) {
    ofstream arquivo(filename);
    if (arquivo.is_open()) {
        arquivo << aluno->nome << endl;
        arquivo << aluno->idade << endl;
        arquivo << aluno->serie << endl;
        arquivo.close();
        cout << "Dados salvos com sucesso em " << filename << endl;
    } else {
        cout << "Erro ao abrir o arquivo " << filename << endl;
    }
}

Aluno* carregar_de_arquivo(const char* filename) {
    ifstream arquivo(filename);
    if (arquivo.is_open()) {
        Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
        aluno->nome = new char[tam];
        arquivo.getline(aluno->nome, tam);
        arquivo >> aluno->idade;
        arquivo >> aluno->serie;
        arquivo.close();
        cout << "Dados carregados com sucesso de " << filename << endl;
        return aluno;
    } else {
        cout << "Erro ao abrir o arquivo " << filename << endl;
        return NULL;
    }
}

void desalocar_aluno(Aluno* aluno) {
    if (aluno != NULL) {
        delete[] aluno->nome;
        free(aluno);
    }
}

