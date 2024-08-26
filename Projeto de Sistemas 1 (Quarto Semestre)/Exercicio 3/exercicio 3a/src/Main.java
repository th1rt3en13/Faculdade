import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        int inferior, superior, soma =0;
        do{
            inferior = Integer.parseInt(JOptionPane.showInputDialog("Informe o limite inferior: "));
            superior = Integer.parseInt(JOptionPane.showInputDialog("Informe o limite superior: "));
        } while (superior < inferior);
        for (int i=inferior; i<=superior; i++){
            if (i%2==0){
                soma = i + soma;
            }
        }
        JOptionPane.showMessageDialog(null, "SOMA = "+soma );

    }
}