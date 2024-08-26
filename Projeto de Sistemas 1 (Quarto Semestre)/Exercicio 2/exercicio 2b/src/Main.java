import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        int idade1, idade2, idade3, idade4, maior=0, menor =0;

        idade1 = Integer.parseInt(JOptionPane.showInputDialog("Informe a primeira idade: "));
        idade2 = Integer.parseInt(JOptionPane.showInputDialog("Informe a segunda idade: "));
        idade3 = Integer.parseInt(JOptionPane.showInputDialog("Informe a terceira idade: "));
        idade4 = Integer.parseInt(JOptionPane.showInputDialog("Informe a quarta idade: "));
        
        menor = idade1;
        maior = idade1;

        // maior
        if (idade2 > maior) {
            maior = idade2;
        }
        if (idade3 > maior) {
            maior = idade3;
        }
        if (idade4 > maior) {
            maior = idade4;
        }

        // menor
        if (idade2 < menor) {
            menor = idade2;
        }
        if (idade3 < menor) {
            menor = idade3;
        }
        if (idade4 < menor) {
            menor = idade4;
        }

        JOptionPane.showMessageDialog(null, "A maior idade é: " + maior + "\nA menor idade é: " + menor);
    }
}
