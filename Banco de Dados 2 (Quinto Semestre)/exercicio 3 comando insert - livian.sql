CREATE TABLE Departamento(
   Sigla VARCHAR2(3) PRIMARY KEY,
   Nome VARCHAR2(100) NOT NULL
);

CREATE TABLE Cargo(
  Codigo_cargo NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  Nome VARCHAR2(100) NOT NULL,
  Salario NUMBER(10,2) NOT NULL
);

CREATE TABLE Projeto(
  Codigo NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  Nome VARCHAR2(100) NOT NULL,
  Custo_previsto NUMBER (10,2) ,
  Previsao NUMBER,
  Sigla_depto_resp VARCHAR2(3)
);

ALTER TABLE Projeto
ADD CONSTRAINT fk_sigla_depto
FOREIGN KEY (Sigla_depto_resp)
REFERENCES Departamento (Sigla); --sempre do pai 

--1) Insira os registros abaixo nas seguintes tabelas:
INSERT INTO Departamento VALUES ('TI','TECNOLOGIA DA INFORMACAO');
INSERT INTO Departamento VALUES ('ADM','ADMINISTRACAO');
INSERT INTO Departamento VALUES ('MKT','MARKETING');
INSERT INTO Departamento VALUES ('ENG','ENGENHARIA');
INSERT INTO Departamento VALUES ('FIN','FINANCEIRO');
INSERT INTO Departamento VALUES ('RH','RECURSOS HUMANOS');
INSERT INTO Departamento VALUES ('CTB','CONTABILIDADE');

INSERT INTO Cargo (Nome, Salario) VALUES ('PROGRAMADOR',3000);
INSERT INTO Cargo (Nome, Salario) VALUES ('ANALISTA DE SISTEMAS',5700);
INSERT INTO Cargo (Nome, Salario) VALUES ('ANALISTA FINANCEIRO',4200);
INSERT INTO Cargo (Nome, Salario) VALUES ('GERENTE DE RH',6100);
INSERT INTO Cargo (Nome, Salario) VALUES ('CONTADOR',3400);
INSERT INTO Cargo (Nome, Salario) VALUES ('ENGENHEIRO',9300);
INSERT INTO Cargo (Nome, Salario) VALUES ('ADMINISTRADOR',3900);
INSERT INTO Cargo (Nome, Salario) VALUES ('PUBLICITARIO',4400);
INSERT INTO Cargo (Nome, Salario) VALUES ('MOTORISTA',1800);
INSERT INTO Cargo (Nome, Salario) VALUES ('SECRETARIA',1350);
INSERT INTO Cargo (Nome, Salario) VALUES ('AUXILIAR DE SERVICOS GERAIS',1230);
INSERT INTO Cargo (Nome, Salario) VALUES ('DBA',12600);

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Atualizacao WIN10',30000,6,'TI');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Migracao MS Outlook',17000,4,'TI');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Plano Cargos e Salarios',80000,24,'RH');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Redes Sociais',55000,12,'MKT');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Aquisicao de Novos Equipamentos',210000,30,'ENG');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Renovacao moveis do escritorio',120000,8,'ADM');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Desenvolvimento Intranet',220000,12,'TI');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Implantacao novo E-Social',3000,2,'CTB');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Energia Solar',420000,7,'ENG');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Renovacao frota veicular',650000,24,'ADM');

INSERT INTO Projeto (Nome, Custo_previsto, Previsao, Sigla_depto_resp)
VALUES ('Budget anual',3460000,12,'FIN');

--2) Insira 10 funcionários.
--priemiro criar tabela funcionario
CREATE TABLE Funcionario (
  Codigo NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  Nome VARCHAR2(100) NOT NULL,
  Sigla_depto VARCHAR2(3),
  Codigo_cargo NUMBER
);

--constraint
ALTER TABLE Funcionario(
  ADD CONSTRAINT fk_func_depto
  FOREIGN KEY (Sigla_depto)
  REFERENCES Departamento(Sigla)
);

ALTER TABLE Funcionario(
  ADD CONSTRAINT fk_func_cargo
  FOREIGN KEY (Codigo_cargo)
  REFERENCES Cargo(Codigo_cargo)
);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Carlos Silva','TI',1);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Mariana Souza','TI',2);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Ricardo Alves','FIN',3);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Fernanda Lima','RH',4);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('João Pereira','CTB',5);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Paulo Martins','ENG',6);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Ana Costa','ADM',7);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Bruno Rocha','MKT',8);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Lucas Fernandes','ADM',9);

INSERT INTO Funcionario (Nome, Sigla_depto, Codigo_cargo)
VALUES ('Juliana Ramos','ADM',10);

--3) Insira dependentes para 6 funcionários.
--criar tabela dependentes

CREATE TABLE Dependente(
  Codigo NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
  Nome VARCHAR2(100) NOT NULL,
  Codigo_funcinario NUMBER
);

ALTER TABLE Dependente(
  ADD COSNTRAINT fk_dependente_func
  FOREIGN KEY (Codigo_funcinario)
  REFERENCES Funcionario(Cargo)
);

INSERT INTO Dependente (Nome, Codigo_funcionario)
VALUES ('Pedro Silva',1);

INSERT INTO Dependente (Nome, Codigo_funcionario)
VALUES ('Lucas Souza',2);

INSERT INTO Dependente (Nome, Codigo_funcionario)
VALUES ('Maria Alves',3);

INSERT INTO Dependente (Nome, Codigo_funcionario)
VALUES ('Julia Lima',4);

INSERT INTO Dependente (Nome, Codigo_funcionario)
VALUES ('Rafael Pereira',5);

INSERT INTO Dependente (Nome, Codigo_funcionario)
VALUES ('Gabriel Martins',6);

--4) Aloque os 10 funcionários em seus respectivos projetos a sua escolha, sendo 5 deles em andamento e 5 concluídos.
--tabela de relacionamento entre Funcionário e Projeto:
--um funcionário pode participar de vários projetos
--um projeto pode ter vários funcionários

CREATE TABLE Alocacao(
  Codigo_funcionario NUMBER,
  Codigo_projeto NUMBER,
  Status VARCHAR2(15),
  CONSTRAINT pj_alocacao
    PRIMARY KEY (Codigo_funcionario, Codigo_projeto)
);

ALTER TABLE Alocacao(
  ADD CONSTRAINT fk_aloc_func
  FOREIGN KEY (Codigo_funcionario)
  REFERENCES Funcionario(Codigo)
);

ALTER TABLE Alocacao(
  ADD CONSTRAINT fk_aloc_proj
  FOREIGN KEY (Codigo_projeto)
  REFERENCES Projeto(Codigo)
);

INSERT INTO Alocacao VALUES (1,1,'EM ANDAMENTO');
INSERT INTO Alocacao VALUES (2,2,'EM ANDAMENTO');
INSERT INTO Alocacao VALUES (3,3,'EM ANDAMENTO');
INSERT INTO Alocacao VALUES (4,4,'EM ANDAMENTO');
INSERT INTO Alocacao VALUES (5,5,'EM ANDAMENTO');

INSERT INTO Alocacao VALUES (6,6,'CONCLUIDO');
INSERT INTO Alocacao VALUES (7,7,'CONCLUIDO');
INSERT INTO Alocacao VALUES (8,8,'CONCLUIDO');
INSERT INTO Alocacao VALUES (9,9,'CONCLUIDO');
INSERT INTO Alocacao VALUES (10,10,'CONCLUIDO');




















