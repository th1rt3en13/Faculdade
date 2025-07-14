# 🏥 Sistema de Gerenciamento Hospitalar — InovaMed

Este projeto é um sistema desktop desenvolvido em **Java (Swing)** para gerenciamento de uma clínica hospitalar fictícia chamada **InovaMed**. A aplicação foi criada utilizando o **NetBeans** com suporte a GUI Design, seguindo o padrão arquitetural **MVC (Model-View-Controller)**.

---

## 📁 Organização do Projeto

O projeto está dividido em pacotes Java de forma modular:

### `model/`
Contém todas as classes que representam os dados do sistema:
- `Medico`, `Paciente`, `Enfermeiro`, `ConsultaMedica`
- `Endereco`, `ContatoTelemail`, `Genero`, `Responsavel`, `DadoPessoal`
- `AtendimentoHospitalar` (superclasse genérica de entidades)

### `view/`
Todas as interfaces gráficas do sistema:
- `HomeView`: Tela inicial
- `medico_view`, `paciente_view`, `enfermeiro_view`, `consulta_view`: Telas de cadastro e visualização
- GUI construída usando o **GUI Builder do NetBeans**, permitindo uma criação visual e rápida das interfaces.

### `controller/`
Gerencia a lógica de negócios e o armazenamento temporário dos dados em memória (com `ArrayList`). Aqui estão as classes:
- `MedicoController`, `PacienteController`, `EnfermeiroController`, `ConsultaController`

### `ClinicaHospitalar.java`
Classe principal (`main`) que inicia o sistema abrindo a tela inicial (`HomeView`).

---

## 💡 Sobre a InovaMed

A **InovaMed** é uma clínica hospitalar fictícia cujo sistema foi projetado com o intuito de organizar os dados de seus profissionais e pacientes, permitindo:

- Cadastro e edição de médicos, pacientes, enfermeiros e consultas
- Visualização de todos os dados em tabelas interativas
- Interface amigável, limpa e responsiva construída com o GUI Builder

---

## 🔧 Desafios enfrentados no desenvolvimento

- **Gerenciamento de IDs**: Foi implementada uma lógica automática para geração de IDs e controle de edição sem duplicação.
- **Separação de pacotes**: Garantir que cada classe estivesse corretamente importada entre os pacotes `model`, `view` e `controller`.
- **NetBeans GUI Design**: Embora facilite a criação visual da interface, trabalhar com código gerado automaticamente exigiu atenção ao adicionar lógicas personalizadas (eventos, listeners).
- **Persistência de dados**: Inicialmente os dados são mantidos em memória (`ArrayList`). Uma futura melhoria será integrar com banco de dados ou arquivos.

---

## 📦 Funcionalidades principais

- [x] Cadastro de médicos, pacientes, enfermeiros e consultas
- [x] Edição e remoção de registros
- [x] Tabela para visualização dos dados em cada módulo
- [x] Geração de ID automática
- [x] Navegação entre telas via `JLabel` clicável
- [x] Interface visual intuitiva via NetBeans GUI Builder

---

## ▶️ Apresentação do Projeto

Assista à apresentação completa do projeto no link abaixo:

📽️ [Apresentação da InovaMed](https://drive.google.com/file/d/1Qv6jxk_eyA5U_eMIZLFYWMUqG0HWD5Qg/view?usp=drive_link)

---

## 🚀 Tecnologias usadas

- Java 17+
- Swing (Java GUI)
- NetBeans IDE
- MVC (Model-View-Controller)

---
