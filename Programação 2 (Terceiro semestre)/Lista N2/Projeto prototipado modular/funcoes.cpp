#include "funcoes.h"

turma* cadastrar_turma(turma* t) {
    if (t != NULL) {
        cout << "Ja existe uma turma cadastrada." << endl;
        return t;
    }

    cout << endl;
    cout << "CADASTRO DE TURMA" << endl;
    cout << endl;
    turma* tmp = (turma*)malloc(sizeof(turma));

    if (tmp == NULL) {
        printf("Erro na alocacao\n");
        return NULL;
    }

    tmp->professor_titular = cadastrar_professor();
    tmp->Disciplina = cadastrar_disciplina();
    cout << "Informe o numero de alunos: ";
    cin >> tmp->num_alunos;
    tmp->lista_alunos = cadastrar_aluno(tmp->num_alunos);
    return tmp;
}

professor* cadastrar_professor() {
    professor* tmp_p = (professor*)malloc(sizeof(professor));
    if (tmp_p == NULL) {
        printf("Erro na alocacao\n");
        return NULL;
    }

    cout << "Cadastrando dados do professor" << endl;
    cout << "Informe nome do professor: ";
    cin.ignore();
    cin.getline(tmp_p->nome, TAM);

    cout << "Informe sobrenome do professor: ";
    cin.getline(tmp_p->sobrenome, TAM);

    cout << "Informe telefone do professor: ";
    cin >> tmp_p->telefone;
    cout << endl;

    return tmp_p;
}

disciplina* cadastrar_disciplina() {
    disciplina* tmp_d = (disciplina*)malloc(sizeof(disciplina));
    if (tmp_d == NULL) {
        printf("Erro na alocacao\n");
        return NULL;
    }

    cout << "Cadastrando dados da disciplina" << endl;
    cout << "Informe nome da disciplina: ";
    cin.ignore();
    cin.getline(tmp_d->nome_disciplina, TAM);

    cout << "Informe os creditos da disciplina: ";
    cin >> tmp_d->creditos;
    cout << endl;

    return tmp_d;
}

aluno* cadastrar_aluno(int num_alunos) {
    aluno* tmp_a = (aluno*)malloc(num_alunos * sizeof(aluno));
    if (tmp_a == NULL) {
        printf("Erro na alocacao\n");
        return NULL;
    }
    cout << "Cadastrando dados dos alunos" << endl;

    for (int i = 0; i < num_alunos; i++) {
        cout << "Nome completo do aluno " << i + 1 << ": ";
        cin.ignore();
        cin.getline(tmp_a[i].nome_completo, TAM);

        cout << "Email do aluno " << i + 1 << ": ";
        cin.getline(tmp_a[i].email, TAM);

        cout << "Telefone do aluno " << i + 1 << ": ";
        cin >> tmp_a[i].telefone;
        cout << endl;
    }
    cout << endl;
    return tmp_a;
}

void imprimir_turma(turma* t) {
    if (t == NULL) {
        cout << "Nao ha turma cadastrada" << endl;
        return;
    }

    cout << endl;
    cout << ">Professor cadastrado na turma:" << endl;
    cout << "Nome do professor: " << t->professor_titular->nome << endl;
    cout << "Sobrenome do professor: " << t->professor_titular->sobrenome << endl;
    cout << "Telefone do professor: " << t->professor_titular->telefone << endl;
    cout << endl;

    cout << ">Disciplina cadastrada na turma:" << endl;
    cout << "Nome da disciplina: " << t->Disciplina->nome_disciplina << endl;
    cout << "Creditos da disciplina: " << t->Disciplina->creditos << endl;
    cout << endl;

    cout << ">Alunos cadastrados na turma:" << endl;
    for (int i = 0; i < t->num_alunos; ++i) {
        cout << "Aluno " << i + 1 << ":" << endl;
        cout << "Nome completo do aluno: " << t->lista_alunos[i].nome_completo << endl;
        cout << "Email do aluno: " << t->lista_alunos[i].email << endl;
        cout << "Telefone do aluno: " << t->lista_alunos[i].telefone << endl;
        cout << endl;
    }
}

void desalocar(turma* t) {
    if (t != NULL) {
        if (t->professor_titular != NULL) {
            free(t->professor_titular);
        }
        if (t->Disciplina != NULL) {
            free(t->Disciplina);
        }
        if (t->lista_alunos != NULL) {
            free(t->lista_alunos);
        }
        free(t);
    }
}

