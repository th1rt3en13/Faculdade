import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        int num =0, primeiro =0, segundo=0, soma=0;
        num = Integer.parseInt(JOptionPane.showInputDialog("Informe um inteiro de dois digitos: "));
        primeiro = num/10;
        segundo = num%10;
        soma = primeiro+segundo;
        JOptionPane.showMessageDialog(null, "primeiro digito = "+ primeiro+" segundo digito = "+segundo+ " soma dos dois digitos = "+soma );

    }
}