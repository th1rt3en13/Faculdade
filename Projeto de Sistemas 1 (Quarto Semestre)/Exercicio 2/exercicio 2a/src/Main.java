import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        double prod=0, desc =0, valor_final=0;
        int code=0, qtd=0;

        qtd = Integer.parseInt(JOptionPane.showInputDialog("Informe a quantidade de produtos: "));

        for (int i=0; i<qtd; i++) {
            prod = Double.parseDouble(JOptionPane.showInputDialog("Informe o valor do produto: "));
            code = Integer.parseInt(JOptionPane.showInputDialog("Informe o código: "));

            if (code == 1) {
                desc = prod * 0.05;
                valor_final = prod - desc;
            } else if (code == 2) {
                desc = prod * 0.1;
                valor_final = prod - desc;
            } else if (code == 3) {
                desc = prod * 0.2;
                valor_final = prod - desc;
            } else if (code == 4) {
                desc = prod * 0.5;
                valor_final = prod - desc;
            } else {
                JOptionPane.showMessageDialog(null, "Codigo invalido");
                continue;
            }
            JOptionPane.showMessageDialog(null, "Desconto = " + desc + " Valor final = " + valor_final);
        }

    }
}