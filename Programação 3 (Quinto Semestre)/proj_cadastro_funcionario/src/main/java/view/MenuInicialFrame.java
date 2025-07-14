package view;

import javax.swing.JOptionPane;

public class MenuInicialFrame extends javax.swing.JFrame {

    // Componentes da interface
    private javax.swing.JButton botaoCadastrar;
    private javax.swing.JButton botaoVisualizar;
    private javax.swing.JButton botaoSair;

    public MenuInicialFrame() {
        initComponents(); // Inicializa os componentes
    }

    private void initComponents() {
        // Inicializa os componentes
        botaoCadastrar = new javax.swing.JButton();
        botaoVisualizar = new javax.swing.JButton();
        botaoSair = new javax.swing.JButton();

        // Configurações da janela
        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Menu Inicial");

        // Configurações do botão "Cadastrar Funcionário"
        botaoCadastrar.setText("Cadastrar Funcionário");
        botaoCadastrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoCadastrarActionPerformed(evt);
            }
        });

        // Configurações do botão "Visualizar Funcionários"
        botaoVisualizar.setText("Visualizar Funcionários");
        botaoVisualizar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoVisualizarActionPerformed(evt);
            }
        });

        // Configurações do botão "Sair"
        botaoSair.setText("Sair");
        botaoSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoSairActionPerformed(evt);
            }
        });

        // Layout da janela
        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(50, 50, 50)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(botaoCadastrar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(botaoVisualizar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(botaoSair, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(50, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(50, 50, 50)
                .addComponent(botaoCadastrar, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(20, 20, 20)
                .addComponent(botaoVisualizar, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(20, 20, 20)
                .addComponent(botaoSair, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(50, Short.MAX_VALUE))
        );

        pack(); // Ajusta o tamanho da janela
        setLocationRelativeTo(null); // Centraliza a janela na tela
    }

    private void botaoCadastrarActionPerformed(java.awt.event.ActionEvent evt) {
        // Abre a tela de cadastro
        CadastroFrame cadastroFrame = new CadastroFrame();
        cadastroFrame.setVisible(true);
        this.dispose(); // Fecha o menu inicial
    }

    private void botaoVisualizarActionPerformed(java.awt.event.ActionEvent evt) {
        // Abre a tela de visualização
        VisualizacaoFrame visualizacaoFrame = VisualizacaoFrame.getInstance();
        visualizacaoFrame.atualizarTabela(); // Atualiza a tabela antes de exibir
        visualizacaoFrame.setVisible(true);
        this.dispose(); // Fecha o menu inicial
    }

    private void botaoSairActionPerformed(java.awt.event.ActionEvent evt) {
        // Fecha a aplicação
        int confirmacao = JOptionPane.showConfirmDialog(this, "Deseja realmente sair?", "Sair", JOptionPane.YES_NO_OPTION);
        if (confirmacao == JOptionPane.YES_OPTION) {
            System.exit(0);
        }
    }

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MenuInicialFrame().setVisible(true);
            }
        });
    }
}