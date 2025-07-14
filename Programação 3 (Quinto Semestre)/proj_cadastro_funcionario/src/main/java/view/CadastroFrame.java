package view;

import controller.FuncionarioController;
import model.Funcionario;
import javax.swing.JOptionPane;

public class CadastroFrame extends javax.swing.JFrame {

    // Componentes da interface
    private javax.swing.JButton botaoEnviar;
    private javax.swing.JButton botaoVoltar;
    private javax.swing.JTextField campoNome;
    private javax.swing.JTextField campoIdade;
    private javax.swing.JTextField campoSalario;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;

    public CadastroFrame() {
        initComponents(); // Inicializa os componentes
    }

    private void initComponents() {
        // Inicializa os componentes
        jLabel1 = new javax.swing.JLabel();
        campoNome = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        campoIdade = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        campoSalario = new javax.swing.JTextField();
        botaoEnviar = new javax.swing.JButton();
        botaoVoltar = new javax.swing.JButton();

        // Configurações da janela
        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Cadastro de Funcionário");

        // Configurações do rótulo "Nome:"
        jLabel1.setText("Nome:");

        // Configurações do campo de texto "Nome"
        campoNome.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoNomeActionPerformed(evt);
            }
        });

        // Configurações do rótulo "CADASTRO:"
        jLabel2.setText("CADASTRO:");

        // Configurações do rótulo "Idade:"
        jLabel3.setText("Idade:");

        // Configurações do campo de texto "Idade"
        campoIdade.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoIdadeActionPerformed(evt);
            }
        });

        // Configurações do rótulo "Salário:"
        jLabel4.setText("Salário:");

        // Configurações do campo de texto "Salário"
        campoSalario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoSalarioActionPerformed(evt);
            }
        });

        // Configurações do botão "Enviar"
        botaoEnviar.setText("Enviar");
        botaoEnviar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoEnviarActionPerformed(evt);
            }
        });

        // Configurações do botão "Voltar"
        botaoVoltar.setText("Voltar");
        botaoVoltar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoVoltarActionPerformed(evt);
            }
        });

        // Layout da janela
        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(34, 34, 34)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel1)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(campoIdade, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 262, Short.MAX_VALUE)
                    .addComponent(campoSalario, javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(campoNome))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(161, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addGap(167, 167, 167))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(botaoEnviar, javax.swing.GroupLayout.PREFERRED_SIZE, 82, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(157, 157, 157))))
            .addGroup(layout.createSequentialGroup()
                .addComponent(botaoVoltar)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(botaoVoltar)
                .addGap(40, 40, 40)
                .addComponent(jLabel2)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(campoNome, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(campoIdade, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(campoSalario, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(botaoEnviar)
                .addContainerGap(72, Short.MAX_VALUE))
        );

        pack(); // Ajusta o tamanho da janela
        setLocationRelativeTo(null); // Centraliza a janela na tela
    }

    private void campoNomeActionPerformed(java.awt.event.ActionEvent evt) {
        // TODO: Adicionar código para tratar o evento do campo "Nome"
    }

    private void campoIdadeActionPerformed(java.awt.event.ActionEvent evt) {
        // TODO: Adicionar código para tratar o evento do campo "Idade"
    }

    private void campoSalarioActionPerformed(java.awt.event.ActionEvent evt) {
        // TODO: Adicionar código para tratar o evento do campo "Salário"
    }

    private void botaoEnviarActionPerformed(java.awt.event.ActionEvent evt) {
        try {
            // Coleta os dados dos campos
            String nome = campoNome.getText().trim();
            String idadeTexto = campoIdade.getText().trim();
            String salarioTexto = campoSalario.getText().trim();

            // Verifica se algum campo está em branco
            if (nome.isEmpty() || idadeTexto.isEmpty() || salarioTexto.isEmpty()) {
                throw new IllegalArgumentException("Todos os campos são obrigatórios!");
            }

            // Valida o campo "Nome" (apenas letras e espaços)
            if (!nome.matches("[a-zA-Z\\s]+")) {
                throw new IllegalArgumentException("O nome deve conter apenas letras e espaços!");
            }

            // Converte e valida a idade
            int idade = Integer.parseInt(idadeTexto);
            if (idade <= 0) {
                throw new IllegalArgumentException("A idade deve ser maior que zero!");
            }

            // Converte e valida o salário
            double salario = Double.parseDouble(salarioTexto);
            if (salario <= 0) {
                throw new IllegalArgumentException("O salário deve ser maior que zero!");
            }

            // Cria o funcionário
            Funcionario funcionario = new Funcionario(nome, idade, "Cargo Padrão", salario);

            // Adiciona o funcionário no controller
            FuncionarioController controller = FuncionarioController.getInstance();
            controller.adicionarFuncionario(funcionario);

            // Exibe mensagem de sucesso
            JOptionPane.showMessageDialog(this, "Funcionário cadastrado com sucesso!");

            // Limpa os campos
            campoNome.setText("");
            campoIdade.setText("");
            campoSalario.setText("");

            // Atualiza a tabela na instância existente de VisualizacaoFrame
            VisualizacaoFrame visualizacaoFrame = VisualizacaoFrame.getInstance();
            visualizacaoFrame.atualizarTabela();
            visualizacaoFrame.setVisible(true);

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Idade e salário devem ser números válidos.", "Erro", JOptionPane.ERROR_MESSAGE);
        } catch (IllegalArgumentException e) {
            JOptionPane.showMessageDialog(this, e.getMessage(), "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void botaoVoltarActionPerformed(java.awt.event.ActionEvent evt) {
        // Volta para o menu inicial
        MenuInicialFrame menuInicial = new MenuInicialFrame();
        menuInicial.setVisible(true);
        this.dispose(); // Fecha a janela de cadastro
    }

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new CadastroFrame().setVisible(true);
            }
        });
    }
}