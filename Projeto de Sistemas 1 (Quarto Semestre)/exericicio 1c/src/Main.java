import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        double alt=0, peso=0, imc = 0;
        alt = Double.parseDouble(JOptionPane.showInputDialog("Informe a altura: "));
        peso = Double.parseDouble(JOptionPane.showInputDialog("Informe o peso: "));

        imc = peso/(Math.pow(alt,2));

        if (imc<18.5){
            JOptionPane.showMessageDialog(null,"IMC: "+imc+" Abaixo do peso");
        } else if (imc>=18.5 && imc<24.4){
            JOptionPane.showMessageDialog(null,"IMC: "+imc+" Ideal");
        } else if (imc>=24.5 && imc<29.9){
            JOptionPane.showMessageDialog(null,"IMC: "+imc+" Pre obesidade");
        } else if(imc>=30 && imc<34.9){
            JOptionPane.showMessageDialog(null,"IMC: "+imc+" Obesidade classe I");
        } else if (imc>=35 && imc<39.9){
            JOptionPane.showMessageDialog(null,"IMC: "+imc+" Obesidade classe II");
        } else {
            JOptionPane.showMessageDialog(null,"IMC: "+imc+" Obesidade classe III");
        }
    }
}