import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        float base=0, altura=0, perimetro=0, area=0;
        base= Float.parseFloat(JOptionPane.showInputDialog("Indique a base: "));
        altura= Float.parseFloat(JOptionPane.showInputDialog("Indique a altura: "));

        perimetro = (base*2)+(altura*2);
        area= base*altura;

        JOptionPane.showMessageDialog(null,"Perimetro: "+perimetro+ "\nArea: "+area);
    }
}