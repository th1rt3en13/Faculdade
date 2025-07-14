package view; // Pacote view

import view.MenuInicialFrame; // Importa a classe MenuInicialFrame

public class Main {
    public static void main(String[] args) {
        // Inicia a aplicação
        System.out.println("Aplicação iniciada!");

        // Abre o menu inicial
        MenuInicialFrame menuInicial = new MenuInicialFrame();
        menuInicial.setVisible(true);
    }
}
