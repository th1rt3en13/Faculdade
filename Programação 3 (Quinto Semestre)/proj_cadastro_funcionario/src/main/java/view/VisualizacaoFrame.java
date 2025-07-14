package view;

import controller.FuncionarioController;
import model.Funcionario;
import javax.swing.table.DefaultTableModel;
import java.util.List;

public class VisualizacaoFrame extends javax.swing.JFrame {
    private static VisualizacaoFrame instance;

    // Componentes da interface
    private javax.swing.JButton botaoVoltar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable tabelaFuncionarios;

    // Construtor privado para evitar criação direta de instâncias
    private VisualizacaoFrame() {
        initComponents(); // Inicializa os componentes
        atualizarTabela(); // Atualiza a tabela com os dados existentes
    }

    // Método estático para obter a instância única
    public static VisualizacaoFrame getInstance() {
        if (instance == null) {
            instance = new VisualizacaoFrame();
        }
        return instance;
    }

    // Método para atualizar a tabela com os dados dos funcionários
    public void atualizarTabela() {
        FuncionarioController controller = FuncionarioController.getInstance();
        List<Funcionario> funcionarios = controller.listarFuncionarios();

        // Obtém o modelo da tabela
        DefaultTableModel model = (DefaultTableModel) tabelaFuncionarios.getModel();

        // Limpa a tabela antes de adicionar os dados
        model.setRowCount(0);

        // Adiciona os dados à tabela
        for (Funcionario funcionario : funcionarios) {
            model.addRow(new Object[]{
                funcionario.getNome(),
                funcionario.getIdade(),
                funcionario.getCargo(),
                funcionario.getSalario()
            });
        }
    }

    // Método para inicializar os componentes da interface
    private void initComponents() {
        // Inicializa os componentes
        jScrollPane1 = new javax.swing.JScrollPane();
        tabelaFuncionarios = new javax.swing.JTable();
        jLabel1 = new javax.swing.JLabel();
        botaoVoltar = new javax.swing.JButton();

        // Configurações da janela
        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Visualização de Funcionários");

        // Configurações da tabela
        tabelaFuncionarios.setModel(new javax.swing.table.DefaultTableModel(
            new Object[][] {}, // Dados da tabela (inicialmente vazios)
            new String[] {"Nome", "Idade", "Cargo", "Salário"} // Nomes das colunas
        ));
        jScrollPane1.setViewportView(tabelaFuncionarios);

        // Configurações do rótulo "Funcionários Cadastrados:"
        jLabel1.setText("Funcionários Cadastrados:");

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
                .addGap(74, 74, 74)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER)
                    .addComponent(jLabel1)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 233, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(93, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addComponent(botaoVoltar)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addComponent(botaoVoltar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 13, Short.MAX_VALUE)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 184, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(52, 52, 52))
        );

        pack(); // Ajusta o tamanho da janela
        setLocationRelativeTo(null); // Centraliza a janela na tela
    }

    // Método para tratar o evento do botão "Voltar"
    private void botaoVoltarActionPerformed(java.awt.event.ActionEvent evt) {
        // Volta para o menu inicial
        MenuInicialFrame menuInicial = new MenuInicialFrame();
        menuInicial.setVisible(true);
        this.dispose(); // Fecha a janela de visualização
    }

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VisualizacaoFrame().setVisible(true);
            }
        });
    }
}