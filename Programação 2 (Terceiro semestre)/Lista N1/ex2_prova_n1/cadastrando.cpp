//cadastrando.cpp
#include "cadastrando.h"
#define tam 20

Aluno* cadastrar_aluno(){
	
	Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
	
	cout << "Informe nome do aluno: ";
    cin.ignore(); // Limpar o buffer do teclado
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
