import javax.swing.*;
import java.text.DecimalFormat;

public class Main {
    public static void main(String[] args) {
        //TESTES

        //slide 4
        //JOptionPane.showMessageDialog(null, Math.ceil(5.2));
        System.out.println(Math.floor(5.2));

        //slide 5
        int valor1 = 5, valor2 =7;
        System.out.println(Math.max(valor1, valor2));
        System.out.println(Math.min(valor1, valor2));

        //slide 7
        System.out.println((Math.random()*100));
        System.out.println((int)(Math.random()*10));
        System.out.println((int)(Math.random()*100));
        System.out.println((int)(Math.random()*1000));

        //slide 10
        DecimalFormat df = new DecimalFormat();
        df.applyPattern("00.00");
        System.out.println(df.format(0.9700));
        df.applyPattern("###,###.00");
        System.out.println(df.format(1500));
        df.applyPattern("###,###.##");
        System.out.println(df.format(1500));

        //slide 12
        String obj = "Sala de aula";
        System.out.println(obj.length());
        System.out.println(obj.charAt(11));
        System.out.println(obj.toUpperCase());
        System.out.println(obj.toLowerCase());
        System.out.println(obj.substring(8,12));
        System.out.println(obj.trim());
        System.out.println(obj.replace("a", "0"));
        //System.out.println(obj = String.valueOf(13));
        System.out.println(obj.indexOf("a", 0));
    }
}